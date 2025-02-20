#include "tim.h"

int main(void)
{
    tim2_1hz_init();
    uart2_tx_rx_init();
    tim4_pd12_output_compare();
    while(1)
    {
        /*wait for UIF*/
        while(!(TIM2->SR & TIM_SR_UIF)){}
        /*Clear UIF*/
        TIM2->SR &= ~TIM_SR_UIF;
        printf("Hello from STM32F4.............\n\r");
    }
}