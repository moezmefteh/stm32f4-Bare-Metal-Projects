#include "uart.h"

char uart2_read(void)
{
    /*Check the Receiver Data Register is not empty*/
    /* RXNEIE: RXNE interrupt enable*/
    while(!(USART2->SR & USART_CR1_RXNEIE)){}
    /*Read Data*/
    return (char)(USART2->DR & 0xFF);
}
int __io_putchar(int ch)
{
    uart2_write(ch);
    return ch;
}
void uart2_write(int ch)
{
    /*Check the Transmit Data Register is empty*/
    while(!(USART2->SR & USART_CR1_TXEIE)){}
    /*write to transmit data register*/
    USART2->DR = (ch & 0xFF);
}
void uart2_tx_rx_init(void)
{
    /******************Configure UART GPIO pins******************/
    /*Enable clock access to GPIOA*/
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    /*Set PA2 mode to alternate function mode in GPIOx_MODER register*/
    GPIOA->MODER |= GPIO_MODER_MODE2_1;
    GPIOA->MODER &= ~GPIO_MODER_MODE2_0;
    /*set PA2 (AFRL2) alternate function type to UART_TX (AF07) in GPIOx_AFRL register*/
    GPIOA->AFR[0] |= GPIO_AFRL_AFRL2_0;
    GPIOA->AFR[0] |= GPIO_AFRL_AFRL2_1;
    GPIOA->AFR[0] |= GPIO_AFRL_AFRL2_2;
    GPIOA->AFR[0] &= ~GPIO_AFRL_AFRL2_3;

    /*Set PA3 mode to alternate function mode in GPIOx_MODER register*/
    GPIOA->MODER |= GPIO_MODER_MODER3_1;
    GPIOA->MODER &= ~GPIO_MODER_MODER3_0;
    /*set PA3 (AFRL2) alternate function type to UART_RX (AF07) in GPIOx_AFRL register*/
    GPIOA->AFR[0] |= GPIO_AFRL_AFRL3_0;
    GPIOA->AFR[0] |= GPIO_AFRL_AFRL3_1;
    GPIOA->AFR[0] |= GPIO_AFRL_AFRL3_2;
    GPIOA->AFR[0] &= ~GPIO_AFRL_AFRL3_3;

    /******************Configure UART Module******************/
    /*Enable clock access to UART2*/
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    /*Configure Baudrate*/
    uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);
    /*Configure the transfert direction*/
    USART2->CR1 = USART_CR1_TE;
    USART2->CR1 |= USART_CR1_UE;
    /*Enable Receiver*/
    USART2->CR1 |= USART_CR1_RE;
}
void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate)
{
    USARTx->BRR = compte_uart_bd(PeriphClk,BaudRate);
}
uint16_t compte_uart_bd(uint32_t PeriphClk, uint32_t BaudRate)
{
    return ((uint16_t)((PeriphClk + (BaudRate/2U))/BaudRate) & 0xFFFF);
}