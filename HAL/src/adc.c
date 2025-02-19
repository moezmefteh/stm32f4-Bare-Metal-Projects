#include "adc.h"

void start_continuous_conversion(void)
{
    /*Enable continuous conversion*/
    ADC1->CR2 |= ADC_CR2_CONT;
    /*start adc conversion*/
    ADC1->CR2 |= ADC_CR2_SWSTART;
}
uint32_t adc_read(void)
{
    /*wait for conversion to be completed*/
    while(!(ADC1->SR & ADC_SR_EOC)){}
    /*read converted result*/
    return (ADC1->DR);
}
void start_single_conversion(void)
{
    /*start adc conversion*/
    ADC1->CR2 |= ADC_CR2_SWSTART;
}
void pa1_adc_init(void)
{
    /******************Configure ADC GPIO pins******************/
    /*Enable clock access to GPIOA*/
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    /*Set PA1 mode to analog mode in GPIOx_MODER register*/
    GPIOA->MODER |= GPIO_MODER_MODER1_0;
    GPIOA->MODER |= GPIO_MODER_MODER1_1;

    /******************Configure ADC Module******************/
    /*Enable clock access to ADC*/
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
    /*Configure the ADC params*/
    /*Conversion sequence start*/
    ADC1->SQR3 = ADC_SQR3_SQ1_0;
    /*Conversion sequence length*/
    ADC1->SQR1 &= ~ADC_SQR1_L;
    /*Enable ADC module*/
    ADC1->CR2 |= ADC_CR2_ADON;
}