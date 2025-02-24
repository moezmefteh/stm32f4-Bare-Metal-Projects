#include "exti.h"

int main(void)
{
    uart2_tx_rx_init();
    printf("Hello from STM32F4.............\n\r");
    pa0_exti_init();
    while (1)
    {

    }
    
}
