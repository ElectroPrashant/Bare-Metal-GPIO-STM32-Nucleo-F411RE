# Bare-Metal-LED-Control-STM32-Nucleo-F411RE
This project demonstrates bare-metal programming on the STM32F411RE microcontroller by toggling the onboard user LED without using HAL, CMSIS drivers, or external libraries.

The LED connected to PA5 (LD2) on the board is toggled by directly accessing the microcontroller’s memory-mapped GPIO registers.

The program enables the GPIO peripheral clock, configures PA5 as an output pin, and continuously toggles the LED using register-level bit manipulation.

- Hardware

Board used:

NUCLEO-F411RE

On this board:

User LED (LD2) → GPIOA Pin 5

- What This Project Demonstrates

The program performs the following steps:

Defines the STM32 peripheral memory map

Maps hardware registers using C structures

Enables the GPIOA clock through the RCC register

Configures PA5 as a general purpose output

Toggles the LED continuously using the GPIO output data register

All hardware access is done directly at the register level.

- Key Concepts

Bare-metal embedded programming

Memory-mapped I/O

Register-level peripheral control

Bit manipulation in C

GPIO configuration

Hardware abstraction using C structs

- Important Registers Used

Register	         Purpose
RCC_AHB1ENR	       Enables clock for GPIO peripherals
GPIOA_MODER	       Configures the mode of GPIO pins
GPIOA_ODR	         Controls the output state of GPIO pins

- Code Behavior
Enable GPIOA Clock
RCC->AHB1ENR |= GPIOAEN;

Configure PA5 as Output
MODER5[1:0] = 01

Toggle LED
GPIOA->ODR ^= LED_PIN;

A simple delay loop is used to make the LED blinking visible.
