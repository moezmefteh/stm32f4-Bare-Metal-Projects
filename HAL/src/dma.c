#include "dma.h"

void dma1_stream6_init(uint32_t src, uint32_t dst, uint32_t len)
{
    /*Enable clock access to DMA*/
    RCC->AHB1ENR |= RCC_AHB1ENR_DMA1EN;
    /*Disable DMA1 stream6*/
    DMA1_Stream6->CR &= ~DMA_SxCR_EN;
    /*wait until DMA1 Stream 6 is disabled*/
    while (DMA1_Stream6->CR & DMA_SxCR_EN){}
    
    /*Clear all interrupt flags of stream6*/
    DMA1->HIFCR |= DMA_HIFCR_CFEIF6;
    DMA1->HIFCR |= DMA_HIFCR_CDMEIF6;
    DMA1->HIFCR |= DMA_HIFCR_CTEIF6;
    DMA1->HIFCR |= DMA_HIFCR_CHTIF6;
    DMA1->HIFCR |= DMA_HIFCR_CTCIF6;

    /*Set the destination buffer*/
    DMA1_Stream6->PAR = dst;
    /*Set the source buffer*/
    DMA1_Stream6->M0AR = src;
    /*Set length*/
    DMA1_Stream6->NDTR = len;
    /*Select stream6 CH4*/
    DMA1_Stream6->CR &= ~DMA_SxCR_CHSEL_0;
    DMA1_Stream6->CR &= ~DMA_SxCR_CHSEL_1;
    DMA1_Stream6->CR |= DMA_SxCR_CHSEL_2;

    /*Enable memory increment*/
    DMA1_Stream6->CR |= DMA_SxCR_MINC;
    /*Configure trasfer direction*/
    DMA1_Stream6->CR |= DMA_SxCR_DIR_0;
    DMA1_Stream6->CR &= ~DMA_SxCR_DIR_1;

    /*Enable DMA transfert complete interrupt*/
    DMA1_Stream6->CR |= DMA_SxCR_TCIE;
    /*Enable direct mode and disable FIFO*/
    DMA1_Stream6->FCR &= ~DMA_SxFCR_FEIE;
    /*Enable DMA1 stream6*/
    DMA1_Stream6->CR |= DMA_SxCR_EN;
    /*Enable UART2 transmitter DMA*/
    USART2->CR3 |= USART_CR3_DMAT;
    /*DMA Interrupt enable in NVIC*/
    NVIC_EnableIRQ(DMA1_Stream6_IRQn);
}
void DMA1_Stream6_IRQHandler(void)
{
    if (DMA1->HISR & DMA_HISR_TCIF6)
    {
        /*Clear flag*/
        DMA1->HIFCR |= DMA_HIFCR_CTCIF6;
        /*Do something*/
        dma_callback();
    }
}
void dma_callback(void)
{
    led_toggle();
}