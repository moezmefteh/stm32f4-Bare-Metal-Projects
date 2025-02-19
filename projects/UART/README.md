# STM32 UART Application with picocom

This project demonstrates UART communication on an STM32 microcontroller. It uses `picocom` as the serial terminal to interact with the application. The application sends and receives UART data and provides simple functionality for LED control.

## Features

- **UART Communication**:
  - Send and receive data over UART using a serial terminal.
  - Echo received data back to the UART interface.
- **GPIO LED Control**:
  - Toggle an LED based on received UART input.

## Requirements

### Hardware
- STM32F4 microcontroller (or compatible model).
- USB-to-Serial adapter or direct USB connection for UART communication.
- Onboard or external LED connected to a GPIO pin.

### Software
- GCC ARM toolchain or STM32CubeIDE for compilation and flashing.
- `picocom` for UART communication.

## Using picocom for UART Communication

1. **Install picocom**:
   ```bash
   sudo apt-get install picocom

2. **Connect to STM32 via UART: Identify the UART device name (e.g., /dev/ttyACM0) by running**:
   ```bash
    dmesg | grep tty

3. **Start picocom: Use the following command to start picocom with the correct baud rate (e.g., 115200)**:
   ```bash
    picocom -b 115200 /dev/ttyACM0

4. **Interact with the Application**:

    - On startup, a greeting message is displayed in the terminal.
    - Type 1 to toggle the LED or send other characters to interact with the application.
    - The microcontroller echoes back the received characters.

Exit picocom: To exit picocom, press Ctrl+A followed by Ctrl+X.