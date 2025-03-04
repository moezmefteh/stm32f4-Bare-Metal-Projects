#ifndef __ADC_H__
#define __ADC_H__

#include "stm32f4xx.h"
#include <stdint.h>
#include <stdio.h>

extern void uart2_tx_rx_init(void);
extern void led_toggle(void);
extern void delay(unsigned int count);

uint32_t adc_read(void);
void start_single_conversion(void);
void pa1_adc_init(void);
void start_continuous_conversion(void);

#endif
