#ifndef __SYSTICK_H__
#define __SYSTICK_H__

#include "stm32f4xx.h"
#include "uart.h"
#include "blinky.h"

#define SYSTICK_LOAD_VAL        16000
void systickDelayMs(int delay);

#endif
