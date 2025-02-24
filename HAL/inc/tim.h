#ifndef __TIM_H__
#define __TIM_H__

#include "stm32f4xx.h"
#include <stdio.h>
#include <stdint.h>

extern void uart2_tx_rx_init(void);

void tim2_1hz_init(void);
void tim4_pd12_output_compare(void);
void tim5_pa0_input_capture(void);

#endif
