#include "quantum.h"
#include "i2c_master.h"

#define MCP23017_ADDR 0x40

#define IODIRA 0x00
#define IODIRB 0x01
#define GPPUA  0x0C
#define GPPUB  0x0D
#define GPIOA  0x12
#define GPIOB  0x13

void matrix_init_custom(void) {
    i2c_init();
    debug_enable = true;

    uint8_t data;

    // GPA = rows = outputs
    data = 0x00;
    i2c_write_register(MCP23017_ADDR, IODIRA, &data, 1, 100);

    // GPB = columns = inputs
    data = 0xFF;
    i2c_write_register(MCP23017_ADDR, IODIRB, &data, 1, 100);

    // No pull-ups on row outputs
    data = 0x00;
    i2c_write_register(MCP23017_ADDR, GPPUA, &data, 1, 100);

    // Pull-ups on columns
    data = 0xFF;
    i2c_write_register(MCP23017_ADDR, GPPUB, &data, 1, 100);

    // Idle state: all rows high
    data = 0xFF;
    i2c_write_register(MCP23017_ADDR, GPIOA, &data, 1, 100);
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool changed = false;
    uint8_t cols = 0;

    for (int r = 0; r < MATRIX_ROWS; r++) {
        // all rows high
        uint8_t all_high = 0xFF;
        i2c_write_register(MCP23017_ADDR, GPIOA, &all_high, 1, 100);

        wait_us(50);

        // drive one row low
        uint8_t row_state = (uint8_t)(0xFF & ~(1 << r));
        i2c_write_register(MCP23017_ADDR, GPIOA, &row_state, 1, 100);

        wait_us(200);

        if (i2c_read_register(MCP23017_ADDR, GPIOB, &cols, 1, 100) != I2C_STATUS_SUCCESS) {
            continue;
        }

        matrix_row_t new_state = (matrix_row_t)((~cols) & 0x1F);

        if (current_matrix[r] != new_state) {
            current_matrix[r] = new_state;
            changed = true;
        }
    }

    // restore idle state
    uint8_t all_high = 0xFF;
    i2c_write_register(MCP23017_ADDR, GPIOA, &all_high, 1, 100);

    return changed;
}