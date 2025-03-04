#include "exti.h"

int main(void)
{
    uart2_tx_rx_init();
    tim2_1hz_init();
    tim2_1hz_interrupt_init();
    printf("Hello from STM32F4.............\n\r");
    while (1)
    {

    }
    
}
