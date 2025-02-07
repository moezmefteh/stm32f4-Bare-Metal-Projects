#include "uart.h"


int main(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
}