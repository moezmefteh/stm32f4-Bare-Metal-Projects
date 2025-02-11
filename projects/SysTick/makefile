TARGET = systick
SRCS = systick.c

LINKER_SCRIPT = ../../STM32F407VGTx_FLASH.ld
INCLUDES += ../UART
INCLUDES += ../GPIO

# Generate debug info
DEBUG = 1

# Choose processor
CDEFS  = -DSTM32F407xx
# Enable FPU
#CDEFS += -D__VFP_FP__

include ../../armf4.mk