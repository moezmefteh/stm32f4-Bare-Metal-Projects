#include "tim.h"

int main(void)
{
    init_led();
    tim2_1hz_init();
    uart2_tx_rx_init();
    while(1)
    {
        /*wait for UIF*/
        while(!(TIM2->SR & TIM_SR_UIF)){}
        /*Clear UIF*/
        TIM2->SR &= ~TIM_SR_UIF;
        printf("Hello from STM32F4.............\n\r");
        led_toggle();
    }
}