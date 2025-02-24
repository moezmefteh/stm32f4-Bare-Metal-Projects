#ifndef __ADC_H__
#define __ADC_H__

#include "stm32f4xx.h"
#include <stdint.h>
#include <stdio.h>


uint32_t adc_read(void);
void start_single_conversion(void);
void pa1_adc_init(void);
void start_continuous_conversion(void);

#endif
