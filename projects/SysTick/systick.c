#include "systick.h"

int main(void)
{
    init_led();
    uar2_tx_rx_init();
    while(1)
    {
        printf("Hello from STM32F4.............\n\r");
        led_toggle();
        systickDelayMs(1000);
    }
}

void systickDelayMs(int delay)
{
    /*Configure systick*/
    /*Reload with nbr of clocks per millisecond*/
    SysTick->LOAD = SYSTICK_LOAD_VAL;
    /*Clear systick current value register*/
    SysTick->VAL = 0;
    /*Enable systick and select internal clk src*/
    Systick->CTRL = SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_CLKSOURCE_Msk;

    for(int i = 0; i < delay; i++){
        /*wait until the COUNTFLAG is set*/
        while(!(Systick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)){}
    }
    Systick->CTRL = 0;
}