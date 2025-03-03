#include "exti.h"

int main(void)
{
    uart2_tx_rx_init();
    uart2_rx_interrupt_init();
    printf("Hello from STM32F4.............\n\r");
    while (1)
    {

    }
    
}
