#ifndef __UART_H__
#define __UART_H__

#include "stm32f4xx.h"
#include <stdint.h>
#include <stdio.h>

extern void init_led(void);
extern void uart2_tx_rx_init(void);
extern void led_toggle(void);

#define SYS_FREQ            16000000
#define APB1_CLK            SYS_FREQ
#define UART_BAUDRATE       115200
#define LED_PIN_1 12

void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate);
uint16_t compte_uart_bd(uint32_t PeriphClk, uint32_t BaudRate);
void uart2_tx_rx_init(void);
void uart2_write(int ch);
char uart2_read(void);
void init_led_12(void);

#endif
