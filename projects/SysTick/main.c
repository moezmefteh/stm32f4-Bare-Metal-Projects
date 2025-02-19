#include "systick.h"

int main(void)
{
    init_led();
    uart2_tx_rx_init();
    while(1)
    {
        printf("Hello from STM32F4.............\n\r");
        led_toggle();
        systickDelayMs(1000);
    }
}