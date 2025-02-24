TARGET = systick
SRC_DIR := $(CURDIR)
SRCS = $(wildcard $(SRC_DIR)/*.c)

PRO_DIR := ../..
SRCS += $(HAL_SRC)/systick.c
SRCS += $(HAL_SRC)/uart.c
SRCS += $(HAL_SRC)/syscalls.c
SRCS += $(HAL_SRC)/gpio.c

SRCS += $(PRO_DIR)/Startup/stm32_startup_f4.c
#SRCS += $(PRO_DIR)/Startup/startup_stm32f407vgtx.s

LINKER_SCRIPT = $(PRO_DIR)/STM32F407VGTx_FLASH.ld

CFLAGS += -mcpu=cortex-m4 -mthumb

LDFLAGS += -mcpu=cortex-m4 -mthumb

# Generate debug info
DEBUG = 1

# Choose processor
CDEFS  = -DSTM32F407xx
# Enable FPU
#CDEFS += -D__VFP_FP__

include $(PRO_DIR)/armf4.mk