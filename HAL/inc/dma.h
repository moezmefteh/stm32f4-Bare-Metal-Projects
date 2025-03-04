#ifndef __DMA_H__
#define __DMA_H__

#include "stm32f4xx.h"
#include <stdio.h>

extern void uart2_tx_rx_init(void);
extern void init_led(void);
extern void led_toggle(void);
void dma1_stream6_init(uint32_t src, uint32_t dst, uint32_t len);
void dma_callback(void);

#endif
