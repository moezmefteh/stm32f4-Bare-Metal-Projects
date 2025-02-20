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
void tim4_pd12_output_compare(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

    GPIOD->MODER |= GPIO_MODER_MODER12_0;
    GPIOD->MODER &= ~GPIO_MODER_MODER12_1;
    /*set PD12 alternate function type to TIM2_CH1 (AF01) in GPIOx_AFRL register*/
    GPIOD->AFR[1] &= ~GPIO_AFRH_AFRH4_0;
    GPIOD->AFR[1] |= GPIO_AFRH_AFRH4_1;
    GPIOD->AFR[1] &= ~GPIO_AFRH_AFRH4_2;
    GPIOD->AFR[1] &= ~GPIO_AFRH_AFRH4_3;

    /*Enable clock access to tim2*/
    RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
    /*Set prescaler value*/
    TIM4->PSC = 1600 - 1; // 16 000 000 / 1 600 = 10 000
    /*set auto-reload value*/
    TIM4->ARR = 10000 - 1; // 10 000 / 10 000 = 1

    /*Set output compare mode*/
    TIM4->CCMR1 = TIM_CCMR1_OC1M_0 | TIM_CCMR1_OC1M_1;
    /*Enable TIM4 ch1 in compare mode*/
    TIM4->CCER |= TIM_CCER_CC1E;

    /*clear counter*/
    TIM4->CNT = 0;
    /*Enable timer*/
    TIM4->CR1 |= TIM_CR1_CEN;
}