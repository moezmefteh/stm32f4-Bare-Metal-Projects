TARGET = uart
SRCS = uart.c

LINKER_SCRIPT = ../../STM32F407VGTx_FLASH.ld
#LINKER_SCRIPT = ../../flash/STM32F407VGTX_FLASH.ld

# Generate debug info
DEBUG = 1

# Choose processor
CDEFS  = -DSTM32F407xx
# Enable FPU
#CDEFS += -D__VFP_FP__

include ../../armf4.mk

BIN_FILE = Debug/uart.bin
ST_FLASH = st-flash

flash: $(BIN_FILE)
	$(ST_FLASH) write $(BIN_FILE) 0x8000000
erase:
	$(ST_FLASH) erase