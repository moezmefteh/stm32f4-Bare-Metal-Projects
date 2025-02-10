#include "uart.h"

int main(void)
{
    uar2_tx_init();
    while(1)
    {
        uart2_write('Y.............\n\r');
        printf("Hello from STM32F4.............\n\r");
    }
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
void uar2_tx_init(void)
{
    /******************Configure UART GPIO pins******************/
    /*Enable clock access to GPIOA*/
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    /*Set PA2 mode to alternate function mode in GPIOx_MODER register*/
    GPIOA->MODER |= GPIO_MODER_MODER2_0
    GPIOA->MODER &= ~GPIO_MODER_MODER2_1
    /*set PA2 (AFRL2) alternate function type to UART_TX (AF07) in GPIOx_AFRL register*/
    GPIOA->AFR[0] |= GPIO_AFRL_AFRL2_0
    GPIOA->AFR[0] |= GPIO_AFRL_AFRL2_1
    GPIOA->AFR[0] |= GPIO_AFRL_AFRL2_2
    GPIOA->AFR[0] &= ~GPIO_AFRL_AFRL2_3

    /******************Configure UART Module******************/
    /*Enable clock access to UART2*/
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    /*Configure Baudrate*/
    uart_set_baudrate(RCC_APB1RSTR_USART2RST, APB1_CLK, UART_BAUDRATE);
    /*Configure the transfert direction*/
    USART2->CR1 = USART_CR1_TE;
    USART2->CR1 |= USART_CR1_UE;
}
static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate)
{
    USARTx->BRR = compte_uart_bd(PeriphClk,BaudRate);
}
static uint16_t compte_uart_bd(uint32_t PeriphClk, uint32_t BaudRate)
{
    return ((PeriphClk + (BaudRate/2U))/BaudRate);
}