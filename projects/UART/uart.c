#include "uart.h"

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate);
static uint16_t compte_uart_bd(uint32_t PeriphClk, uint32_t BaudRate);

int main(void)
{
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

    /*Enable clock access to UART2*/
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    /*Configure Baudrate*/
    uart_set_baudrate()

}
static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate)
{
    USARTx->BRR = compte_uart_bd(PeriphClk,BaudRate);
}
static uint16_t compte_uart_bd(uint32_t PeriphClk, uint32_t BaudRate)
{
    return ((PeriphClk + (BaudRate/2U))/BaudRate);
}