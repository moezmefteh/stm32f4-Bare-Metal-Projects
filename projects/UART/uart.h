#ifndef __UART_H__
#define __UART_H__

#include "stm32f4xx.h"
#include <stdint.h>

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate);
static uint16_t compte_uart_bd(uint32_t PeriphClk, uint32_t BaudRate);
void uar2_tx_init(void);
void uart2_write(int ch);

#endif
