#include "exti.h"

int main(void)
{
    uart2_tx_rx_init();
    systick_1hz_interrupt();
    printf("Hello from STM32F4.............\n\r");
    while (1)
    {

    }
    
}
