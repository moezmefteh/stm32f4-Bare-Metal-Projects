#ifndef __EXTI_H__
#define __EXTI_H__

#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"

void pa0_exti_init(void);
void exti_pa0_callback(void);
void uart2_rx_interrupt_init(void);
void uart_callback(void);
void pa1_adc_interrupt_init(void);
void adc_callback(void);

#endif
