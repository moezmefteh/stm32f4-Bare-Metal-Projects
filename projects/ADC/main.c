#include "adc.h"

uint32_t sensor_value;
int main(void)
{
    pa1_adc_init();
    uart2_tx_rx_init();
    //start_single_conversion();
    start_continuous_conversion();
    while(1){
        sensor_value = adc_read();
        printf("sensor value : %lu \n\r", sensor_value);
        delay(0x3ffff);
        led_toggle();
    }
}