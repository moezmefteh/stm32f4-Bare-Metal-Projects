# STM32F4 Bare-Metal Projects

## Overview

Welcome to the STM32F4 Bare-Metal Projects repository! This repository is designed to help you develop a deep understanding of the STM32F4 Discovery board by writing bare-metal code for various peripherals. If you want to escape from copying/pasting code you don’t understand, using third-party libraries, and experiencing bugs you can’t resolve, then this is the right place for you.

## Goals

Escape From:

- Using third-party libraries and header files like HAL, LL, and StdPeriph
- Being afraid of technical documentation like the reference manual and datasheet of the chip

Arrive At:

- Building every single line of code from scratch by writing to the microcontroller’s memory space directly
- Using no third-party libraries or header files
- Understanding and writing every single line of code yourself—no Copy/Paste
- Using the debugger effectively to analyze and resolve any bugs
- Developing proficiency in your embedded development skills and confidently taking the next steps

## What You'll Learn

- **Analyzing Chip Documentation:**  
Before developing firmware for any chip, you need to learn how to read the documentation provided by the chip manufacturer.

- **Defining Peripheral Addresses:**  
All components on the microcontroller have an address range. To write to or read from a component, you need to locate its address range in the documentation and properly define the addresses in your code.

- **Creating Registers from Addresses:**  
The addresses in the address range of a component represent the registers of that component. To access these registers, you need to effectively typecast the addresses.

- **Understanding CMSIS:**  
Cortex Microcontroller Software Interface Standard (CMSIS) is a standard developed by Arm for all Cortex-Microcontrollers. This is the standard used in professional firmware development. CMSIS provides a unified interface to the processor and peripherals, making it easier to write low-level code that is portable across different ARM Cortex-M microcontrollers.

- **Developing Peripheral Drivers:**  
How to develop bare-metal drivers for the following peripherals:
    - General Purpose Input/Output (GPIO)
    - Universal Asynchronous Receiver-Transmitter (UART)
    - Analog-to-Digital Converter (ADC)
    - System Tick Timer (SysTick)
    - General Purpose Timers (TIM)
    - Nested Vector Interrupt Controller (NVIC)
    - Direct Memory Access (DMA)
    - Inter-Integrated Circuit (I2C)
    - Serial Peripheral Interface (SPI)

## Getting Started

### Requirements

Before you start, you need to install the following packages:

```bash
sudo apt update
sudo apt install gcc-arm-none-eabi
sudo apt install make
