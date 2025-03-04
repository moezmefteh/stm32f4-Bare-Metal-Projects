#ifndef __EXTI_H__
#define __EXTI_H__

#include "stm32f4xx.h"
#include <stdio.h>

extern void uart2_tx_rx_init(void);
extern void pa1_adc_init(void);
extern void start_continuous_conversion(void);
extern void tim2_1hz_init(void);

void pa0_exti_init(void);
void exti_pa0_callback(void);

void uart2_rx_interrupt_init(void);
void uart_callback(void);

void pa1_adc_interrupt_init(void);
void adc_callback(void);

#define ONE_SEC_LOAD        16000000 
void systick_1hz_interrupt(void);
void systick_callback(void);

void tim2_1hz_interrupt_init(void);
void tim2_callback(void);

#endif
