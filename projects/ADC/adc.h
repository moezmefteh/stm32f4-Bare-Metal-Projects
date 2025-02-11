#ifndef __ADC_H__
#define __ADC_H__

#include "stm32f4xx.h"
include <stdint.h>
uint32_t adc_read(void);
void start_conversion(void);
void pa1_adc_init(void);

#endif
