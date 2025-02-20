#include "tim.h"

void tim2_1hz_init(void)
{
    /*Enable clock access to tim2*/
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    /*Set prescaler value*/
    TIM2->PSC = 1600 - 1; // 16 000 000 / 1 600 = 10 000
    /*set auto-reload value*/
    TIM2->ARR = 10000 - 1; // 10 000 / 10 000 = 1
    /*clear counter*/
    TIM2->CNT = 0;
    /*Enable timer*/
    TIM2->CR1 |= TIM_CR1_CEN;
}