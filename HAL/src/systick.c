#include "systick.h"

void systickDelayMs(int delay)
{
    /*Configure systick*/
    /*Reload with nbr of clocks per millisecond*/
    SysTick->LOAD = SYSTICK_LOAD_VAL;
    /*Clear systick current value register*/
    SysTick->VAL = 0;
    /*Enable systick and select internal clk src*/
    SysTick->CTRL = SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_CLKSOURCE_Msk;

    for(int i = 0; i < delay; i++){
        /*wait until the COUNTFLAG is set*/
        while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)){}
    }
    SysTick->CTRL = 0;
}