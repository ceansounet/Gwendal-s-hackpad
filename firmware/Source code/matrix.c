#include "quantum.h"
#include "i2c_master.h"
#include "mcp23018.h"

#define MCP23017_ADDR 0x20

#define IODIRA 0x00
#define IODIRB 0x01
#define GPIOA  0x12
#define GPIOB  0x13

void matrix_init_custom(void) {
    i2c_init();

    mcp23018_init(MCP23017_ADDR);
}


bool matrix_scan_custom(matrix_row_t current_matrix[]) {

    uint8_t cols;

    i2c_read_register(MCP23017_ADDR, GPIOA, &cols, 1, 10);

    for (int r = 0; r < MATRIX_ROWS; r++) {

        uint8_t row_mask = ~(1 << r);

        i2c_write_register(MCP23017_ADDR, GPIOB, NULL, row_mask, 10);

        wait_us(30);

        i2c_read_register(MCP23017_ADDR, GPIOA, &cols, 1, 10);

        current_matrix[r] = (~cols) & 0x1F;
    }

    return true;
}