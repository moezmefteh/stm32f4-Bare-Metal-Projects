#ifndef __EXTI_H__
#define __EXTI_H__

#include "stm32f4xx.h"
#include "uart.h"

void pa0_exti_init(void);
void exti_pa0_callback(void);
void uart2_rx_interrupt_init(void);
void uart_callback(void);

#endif
