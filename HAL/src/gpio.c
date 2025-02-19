
#include <stdint.h>
#include "gpio.h"

volatile uint32_t delay_ticks;

void init_led(void)
{
    /* Each module is powered separately. In order to turn on a module
     * its relevant clock needs to be enabled first.
     * The clock enables are located at RCC module in the relevant bus registers
     * STM32F4-Discovery board LEDs are connected to GPIOD pins 12, 13, 14, 15.
     * All the GPIO are connected to AHB1 bus, so the relevant register for the
     * clocks is AHB1ENR.
     * More info in Chapter 7 - RCC in RM0090
     */

    /* Enable GPIOD clock (AHB1ENR: bit 3) */
    // AHB1ENR: XXXX XXXX XXXX XXXX XXXX XXXX XXXX 1XXX
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;//GPIODEN;

    /* Make Pin 12 output (MODER: bits 25:24) */
    // Each pin is represented with two bits on the MODER register
    // 00 - input (reset state)
    // 01 - output
    // 10 - alternate function
    // 11 - analog mode

    // We can leave the pin at default value to make it an input pin.
    // In order to make a pin output, we need to write 01 to the relevant
    // section in MODER register
    //                     bit31                                         bit0
    // MODER register bits : xx xx xx 01 XX XX XX XX XX XX XX XX XX XX XX XX
    //                      p15      p12                                  p0
    GPIOD->MODER |= GPIO_MODER_MODER12_0;
    GPIOD->MODER &= ~GPIO_MODER_MODER12_1;
    GPIOD->MODER |= GPIO_MODER_MODER13_0;
    GPIOD->MODER &= ~GPIO_MODER_MODER13_1;
    GPIOD->MODER |= GPIO_MODER_MODER14_0;
    GPIOD->MODER &= ~GPIO_MODER_MODER14_1;
    GPIOD->MODER |= GPIO_MODER_MODER15_0;
    GPIOD->MODER &= ~GPIO_MODER_MODER15_1;
}

void init_button(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;//GPIOAEN;
    GPIOA->MODER |= GPIO_MODER_MODER15_0;
	GPIOA->MODER &= ~GPIO_MODER_MODER15_1;
}

unsigned int read_button(void)
{
    return (GPIOA->IDR & (1 << BUTTON));
}

void led_toggle(void)
{
	GPIOD->ODR ^= (1 << LED_PIN_1);
    GPIOD->ODR ^= (1 << LED_PIN_2);
    GPIOD->ODR ^= (1 << LED_PIN_3);
    GPIOD->ODR ^= (1 << LED_PIN_4);
}
void delay(unsigned int count) {
    while (count--) {
        __asm__("nop");
    }
}