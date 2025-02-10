#ifndef __UART_H__
#define __UART_H__

#include "stm32f4xx.h"
#include <stdint.h>

#define SYS_FREQ            16000000
#define APB1_CLK            SYS_FREQ
#define UART_BAUDRATE       115200

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate);
static uint16_t compte_uart_bd(uint32_t PeriphClk, uint32_t BaudRate);
void uar2_tx_init(void);
void uart2_write(int ch);

#endif
