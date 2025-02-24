#ifndef __SYSTICK_H__
#define __SYSTICK_H__

#include "stm32f4xx.h"
#include <stdio.h>

extern void init_led(void);
extern void uart2_tx_rx_init(void);
extern void led_toggle(void);

#define SYSTICK_LOAD_VAL        16000
void systickDelayMs(int delay);

#endif
