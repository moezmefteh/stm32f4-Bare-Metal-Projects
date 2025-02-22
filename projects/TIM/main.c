#include "tim.h"
int timestamp = 0;

int main(void)
{
    tim2_1hz_init();
    uart2_tx_rx_init();
    printf("Hello from STM32F4.............\n\r");
    tim4_pd12_output_compare();
    tim5_pa0_input_capture();
    while(1)
    {
        /*wait for UIF*/
        //while(!(TIM2->SR & TIM_SR_UIF)){}
        /*Clear UIF*/
        //TIM2->SR &= ~TIM_SR_UIF;
        //printf("Hello from STM32F4.............\n\r");

        /*wait until edge is captured*/
        while(!(TIM5->SR & TIM_SR_CC1IF)){}
        /*Read captured value*/
        timestamp = TIM5->CCR1;
        printf("..........%d\n\r",timestamp);

    }
}