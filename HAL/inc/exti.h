#ifndef __EXTI_H__
#define __EXTI_H__

#include "stm32f4xx.h"
#include "uart.h"

void pa0_exti_init(void);
void exti_pa0_callback(void);

#endif
