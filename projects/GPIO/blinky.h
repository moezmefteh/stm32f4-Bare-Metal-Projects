#ifndef __BLINKY_H__
#define __BLINKY_H__

#include "stm32f4xx.h"
#include <stdint.h>

#define SLOWDELAY    0x3fffff
#define FASTDELAY    0xfffff

#define LED_PIN_1 12
#define LED_PIN_2 13
#define LED_PIN_3 14
#define LED_PIN_4 15
#define BUTTON 0

void init_led(void);
void init_button(void);
void led_toggle(void);
unsigned int read_button(void);
void nop_delay(unsigned int count);
void SysTick_Handler(void);
void delay_ms(uint32_t milliseconds);

#endif
