# Embedded CLI Simulator

A C-based command-line interface (CLI) project that simulates embedded-system commands on a host computer and supports cross-compilation for the Texas Instruments MSP432P401R microcontroller.

The project uses a shared CLI and LED interface with platform-specific LED implementations, demonstrating modular C development and basic embedded software concepts.

## Features

- Interactive command-line interface with a fixed-size input buffer
- Command parsing and validation
- `help` command to display available commands
- `ledon` and `ledoff` commands to control LED state
- `status` command to report the current LED state
- `exit` command to terminate the simulator
- Host implementation for testing without physical hardware
- MSP432P401R-targeted firmware build using ARM GCC
- Makefile configuration for selecting the target platform

## Project Structure

    embedded-cli/
    ├── include/           # Shared CLI and LED interface headers
    ├── src/               # CLI, main program, and LED drivers
    ├── platform/
    │   └── msp432/         # MSP432 headers, startup code, linker script
    ├── Makefile
    └── README.md

## Requirements

Host build:
- GCC
- GNU Make

MSP432 cross-compilation:
- ARM GNU Toolchain (arm-none-eabi-gcc)
- GNU Make

## Build and Run

### Host Simulator

Build:

    make clean
    make PLATFORM=HOST

Run:

    ./embedded-cli

Available commands:

    help
    ledon
    ledoff
    status
    exit

### MSP432P401R Target

Cross-compile the firmware:

    make clean
    make PLATFORM=MSP432

This produces an ARM executable named `embedded-cli`.

Note: The MSP432 target has been cross-compiled and linked, but has not been tested on physical hardware. Interactive UART input/output has not been implemented or verified.

## Technologies

- C (C99)
- GCC and ARM GCC
- GNU Make
- Git
- MSP432P401R device headers and startup code

## Project Goals

This project was built to practice embedded C development, modular driver design, cross-compilation, and using Makefiles to build software for different target platforms.
