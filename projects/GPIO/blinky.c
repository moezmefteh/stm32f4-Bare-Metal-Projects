/*
 * blinky.c
 *
 * author: Moez Mefteh
 * description:
 *    Blinks 4 on-board LED based on the button status.
 *    system clock is running from HSI which is 16 Mhz.
 *    Delay function is just a simple nop sequence.
 *
 * gpio setup steps:
 *   There are at least three steps associated with GPIO:
 *   1. enable GPIOx clock from RCC
 *   2. set the direction of the pins from MODER (input / output)
 *   3. (optional) set the speed of the pins from OSPEEDR
 *   4. (optional) set pins to pull-up or pull-down or
 *         leave them floating from PUPDR
 *   5. (optional) set output type register to push-pull or
 *         open-drain from OTYPER
 *   6. either read from IDR or write to ODR depending on
 *         input or output configuration
 */


#include "blinky.h"

volatile uint32_t delay_ticks;
/*************************************************
* main code starts from here
*************************************************/
int main(void)
{
    init_led();
    init_button();
    while(1)
    {
        // Set delay based on button state
        if(!read_button()) {
            delay_ms(1000);  // Delay when the button is released
        } else {
            delay_ms(500);   // Delay when the button is pressed
        }
        // Toggle LED pins
        led_toggle();
    }
    return 0;
}
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

void SysTick_Handler(void) {
    if (delay_ticks > 0) {
        delay_ticks--;
    }
}

void delay_ms(uint32_t milliseconds) {
    delay_ticks = milliseconds;
    while (delay_ticks > 0);
}