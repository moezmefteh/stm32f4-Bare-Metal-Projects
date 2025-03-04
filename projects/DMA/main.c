#include "dma.h"

int main(void)
{
    char message[31] = "Hello from stm32 DMA transfer\n\r";
    uart2_tx_rx_init();
    printf("Hello from STM32F4.............\n\r");
    init_led();
    dma1_stream6_init((uint32_t) message, (uint32_t) &USART2->DR, 31);

    while(1){

    }
}