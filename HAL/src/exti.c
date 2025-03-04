#include "exti.h"

char key;
uint32_t sensor_value;

void pa0_exti_init(void)
{
    /*Disable global interrupts*/
    __disable_irq();
    /*Enable clock access for GPIOA*/
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    /*Set PA0 as input*/
    GPIOA->MODER &= ~GPIO_MODER_MODER0_0;
    GPIOA->MODER &= ~GPIO_MODER_MODER0_1;
    /*Enable clock access to SYSCFG*/
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
    /*Select PORTA for EXTI0*/
    SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI0_PA;
    /*Unmask EXTI0*/
    EXTI->IMR |= EXTI_IMR_MR0;
    /*Select falling edge trigger*/
    EXTI->FTSR |= EXTI_FTSR_TR0;
    /*Enable EXTI0 line in NVIC*/
    NVIC_EnableIRQ(EXTI0_IRQn);
    /*Enable glabal interrupts*/
    __enable_irq();
}
void EXTI0_IRQHandler(void)
{
	if((EXTI->PR & EXTI_PR_PR0))
	{
		/*clear PR flag*/
		EXTI->PR |= EXTI_PR_PR0;
		/*Do Something*/
		exti_pa0_callback();
	}
}
void exti_pa0_callback(void)
{
    printf("BTN Pressed...\n\r");
}
void uart2_rx_interrupt_init(void)
{
    /*Enable RXNE interrupt*/
    USART2->CR1 |= USART_CR1_RXNEIE;
    /*Enable UART2 interrupt in NVIC*/
    NVIC_EnableIRQ(USART2_IRQn);
}
void uart_callback(void)
{
    key = (char)(USART2->DR & 0xFF);
    if(key == '1')
    {
        printf("1 is recived from UART...\n\r");
    }
    else
    {
        printf("garbage is recived from UART...\n\r");
    }
}
void USART2_IRQHandler(void)
{
    /*Check if RXNE is set*/
    if(USART2->SR & USART_SR_RXNE)
    {
        uart_callback();
    }
}
void pa1_adc_interrupt_init(void)
{
    /*Enable ADC end of conversion interrupt*/
    ADC1->CR1 |= ADC_CR1_EOCIE;
    /*Enable ADC interrupt in NVIC*/
    NVIC_EnableIRQ(ADC_IRQn);
}
void ADC1_2_IRQHandler(void)
{
    /*Check for eoc in SR*/
    if ((ADC1->SR & ADC_SR_EOC) != 0)
    {
        /*Clear EOC*/
        ADC1->SR &= ~ADC_SR_EOC;
        adc_callback();
    }
}
void adc_callback(void)
{
    sensor_value = ADC1->DR;
    printf("sensor value : %lu \n\r", sensor_value);
}
void systick_1hz_interrupt(void)
{
    /*Reload with number of clocks persecond*/
    SysTick->LOAD = ONE_SEC_LOAD - 1;
    /*Clear systick current value register*/
    SysTick->VAL = 0;
    /*Enable systick and select internal clk src*/
    SysTick->CTRL = SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_CLKSOURCE_Msk;
    /*Enable systick interrupt*/
    SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
}
void SysTick_Handler(void)
{
    systick_callback();
}
void systick_callback(void)
{
    printf("1 second passed !! \n\r");
}