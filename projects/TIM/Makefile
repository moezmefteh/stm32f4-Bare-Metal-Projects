TARGET = tim
SRC_DIR := $(CURDIR)
SRCS = $(wildcard $(SRC_DIR)/*.c)

SRCS += $(HAL_SRC)/tim.c
SRCS += $(HAL_SRC)/uart.c
SRCS += $(HAL_SRC)/syscalls.c

LINKER_SCRIPT = ../../STM32F407VGTx_FLASH.ld

# Generate debug info
DEBUG = 1

# Choose processor
CDEFS  = -DSTM32F407xx
# Enable FPU
#CDEFS += -D__VFP_FP__

include ../../armf4.mk