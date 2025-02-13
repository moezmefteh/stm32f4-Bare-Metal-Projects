/****************************************************************
 * File: STM32F407VGTx_FLASH.ld
 * Author: Moez Mefteh
 * Date: 09/06/2023
 * Description: Linker script for STM32F407VGTx microcontroller.
 ****************************************************************/

/* Define the entry point */
ENTRY(Reset_Handler)

/* Specify the memory layout of the target */
MEMORY
{
  FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 1024K
  SRAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 128K
}

/* Define stack top */
_estack = ORIGIN(SRAM) + LENGTH(SRAM); /* End of SRAM */

/* Sections */
SECTIONS
{
    /* Interrupt vector table */
    .isr_vector : {
        . = ALIGN(4);
        KEEP(*(.isr_vector)) /* Startup code */
        . = ALIGN(4);
        _eisr_vector = .;  /* End of isr_vector section */
    } > FLASH

    /* .text section: contains code and read-only data */
    .text :
    {
        . = ALIGN(4);
        *(.text)        /* Code section */
        *(.text*)       /* .text* sections (code) */
        . = ALIGN(4);
        _etext = .;      /* End of text section */
    } > FLASH

    /* .rodata section: Read-only data */
    .rodata :
    {
        . = ALIGN(4);
        *(.rodata)       /* Constants, strings, etc. */
        *(.rodata*)      /* .rodata* sections */
        . = ALIGN(4);
        _erodata = .;    /* End of rodata section */
    } > FLASH
    
    /* Load address of .data section */
    _sidata = LOADADDR(.data);

    /* .data section: Initialized data */
    .data :
    {
        . = ALIGN(4);
        _sdata = .;      /* Start of initialized data in SRAM */
        *(.data)         /* .data sections */
        *(.data*)        /* .data* sections */
        . = ALIGN(4);
        _edata = .;      /* End of initialized data in SRAM */
    } > SRAM AT> FLASH

    /* .bss section: Uninitialized data */
    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss)
        *(.bss*)
        . = ALIGN(4);
        _ebss = .;
        _end = .;  /* Define _end symbol for sbrk */
        end = .;   /* Define end symbol needed by sbrk */
    } > SRAM
}
