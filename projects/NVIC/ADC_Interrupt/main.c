#include "exti.h"

int main(void)
{
    uart2_tx_rx_init();
    pa1_adc_init();
    pa1_adc_interrupt_init();
    start_continuous_conversion();
    printf("Hello from STM32F4.............\n\r");
    while (1)
    {

    }
    
}
