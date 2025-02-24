#include "uart.h"

char key;
int main(void)
{
    uart2_tx_rx_init();
    init_led();
    uart2_write('Y');
    printf("Hello from STM32F4.............\n\r");
    while(1)
    {
        key = uart2_read();
        if(key == '1')
        {
            led_toggle();
        }
        else
        {
            led_toggle();
        }
        uart2_write(key);
    }
}
