/****************************************************************
 * File: STM32F407VGTx_FLASH.ld
 * Author: Moez Mefteh
 * Date: 09/06/2023
 * Description: Linker script for STM32F103C8Tx microcontroller.
 ****************************************************************/

/* Define the entry point */
ENTRY(Reset_Handler)

/* Specify the memory layout of the target */
MEMORY
{
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 1024K
  SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS
{
	/* The startup code into "ROM" Rom type memory */
	.isr_vector :
	{
		. = ALIGN(4);
		KEEP(*(.isr_vector)) /* Startup code */
		. = ALIGN(4);
		_eisr_vector = .;      /* End of isr_vector section */
	} >FLASH

	/* .text section: contains code, vectors, and read-only data */
	.text :
	{
		*(.text)        /* Code section */
		*(.text*)          /* .text* sections (code) */
		. = ALIGN(4);
		_etext = .;      /* End of text section */
	}> FLASH
	
	/* Constant data into "ROM" Rom type memory */
	.rodata :
	{
		. = ALIGN(4);
		*(.rodata)         /* .rodata sections (constants, strings, etc.) */
		*(.rodata*)        /* .rodata* sections (constants, strings, etc.) */
		. = ALIGN(4);
		_erodata = .;      /* End of rodata section */
	} >FLASH
	
	/* _la_data: Load address of .data section for data copy */
      _la_data = LOADADDR(.data);

	/* .data section: initialized data */
	.data :
	{
		_sdata = .;      /* Start of initialized data in SRAM */
		*(.data)           /* .data sections */
		*(.data*)          /* .data* sections */
		. = ALIGN(4);
		_edata = .;      /* End of initialized data in SRAM */
	}> SRAM AT> FLASH

	/* .bss section: uninitialized data (zero-initialized) */
	.bss :
	{
		_sbss = .;       /* Start of uninitialized data in SRAM */
		*(.bss)			/* Uninitialized data section */
    	*(.bss*)
		. = ALIGN(4);
		_ebss = .;       /* End of uninitialized data in SRAM */
	}> SRAM
}
