#include <stdint.h>

extern uint32_t _estack;
extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

extern void SystemInit(void);
extern int main(void);

void Reset_Handler(void);
void Default_Handler(void);

void Reset_Handler(void)
{
    uint32_t *src, *dst;

    // Set stack pointer
    uint32_t *stack_pointer = &_estack;
    __asm volatile("mov sp, %0"::"r"(stack_pointer));

    // Call system initialization
    SystemInit();

    // Copy the data segment initializers from flash to SRAM
    src = &_sidata;
    dst = &_sdata;
    while (dst < &_edata) {
        *dst++ = *src++;
    }

    // Zero fill the bss segment
    dst = &_sbss;
    while (dst < &_ebss) {
        *dst++ = 0;
    }

    // Call static constructors
    extern void __libc_init_array(void);
    __libc_init_array();

    // Call main
    main();

    // Loop forever
    while (1);
}

void Default_Handler(void)
{
    // Infinite loop
    while (1);
}

void NMI_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)           __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void WWDG_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void PVD_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void TAMP_STAMP_IRQHandler(void)    __attribute__((weak, alias("Default_Handler")));
void RTC_WKUP_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
// Define other interrupt handlers similarly...

// Vector table
__attribute__ ((section(".isr_vector")))
void (*const g_pfnVectors[])(void) =
{
    (void (*)(void))&_estack,              // The initial stack pointer
    Reset_Handler,                         // The reset handler
    NMI_Handler,                           // The NMI handler
    HardFault_Handler,                     // The hard fault handler
    MemManage_Handler,                     // The MPU fault handler
    BusFault_Handler,                      // The bus fault handler
    UsageFault_Handler,                    // The usage fault handler
    0, 0, 0, 0,                            // Reserved
    SVC_Handler,                           // SVCall handler
    DebugMon_Handler,                      // Debug monitor handler
    0,                                      // Reserved
    PendSV_Handler,                        // The PendSV handler
    SysTick_Handler,                       // The SysTick handler
    // Define other interrupt handlers similarly...
};
