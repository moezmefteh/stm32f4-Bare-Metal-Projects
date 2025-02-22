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

    GPIOD->MODER &= ~GPIO_MODER_MODER12_0;
    GPIOD->MODER |= GPIO_MODER_MODER12_1;
    /*set PD12 alternate function type to TIM4_CH1 (AF02) in GPIOD_AFRH register*/
    GPIOD->AFR[1] &= ~GPIO_AFRH_AFRH4_0;
    GPIOD->AFR[1] |= GPIO_AFRH_AFRH4_1;
    GPIOD->AFR[1] &= ~GPIO_AFRH_AFRH4_2;
    GPIOD->AFR[1] &= ~GPIO_AFRH_AFRH4_3;

    /*Enable clock access to tim4*/
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
void tim5_pa0_input_capture(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    GPIOA->MODER &= ~GPIO_MODER_MODER0_0;
    GPIOA->MODER |= GPIO_MODER_MODER0_1;
    /*set PA0 alternate function type to TIM5_CH1 (AF02) in GPIOA_AFRL register*/
    GPIOA->AFR[0] &= ~GPIO_AFRL_AFRL0_0;
    GPIOA->AFR[0] |= GPIO_AFRL_AFRL0_1;
    GPIOA->AFR[0] &= ~GPIO_AFRL_AFRL0_2;
    GPIOA->AFR[0] &= ~GPIO_AFRL_AFRL0_3;

    /*Enable clock access to tim5*/
    RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
    /*Set prescaler value*/
    TIM5->PSC = 1600 - 1; // 16 000 000 / 1 600 = 10 000
    /*Set input capture mode*/
    TIM5->CCMR1 = TIM_CCMR1_CC1S_0 | ~TIM_CCMR1_CC1S_1;
    /*set CH1 to capture at rising edge*/
    TIM5->CCER |= TIM_CCER_CC1E;
    /*Enable timer*/
    TIM5->CR1 |= TIM_CR1_CEN;
}