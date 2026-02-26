BOOTLOADER = rp2040
CUSTOM_MATRIX = lite
I2C_DRIVER_REQUIRED = yes
VPATH += drivers/gpio
SRC += drivers/gpio/mcp23018.c