# Homework 2: Dual-LED PWM Control (Task 1)

## Overview
* This project represents Task 1 of Embedded IoT Systems Homework 2.
* It demonstrates dual independent LED fading on an ESP32 microcontroller using different PWM frequencies for each LED.

## Hardware & Wiring Connections
* **LED 1 (Red)**: Anode (+) connected to **GPIO 18** via a 220-ohm resistor.
* **LED 1 (Red)**: Cathode (-) connected to **GND**.
* **LED 2 (Green)**: Anode (+) connected to **GPIO 19** via a 220-ohm resistor.
* **LED 2 (Green)**: Cathode (-) connected to **GND**.

## PWM Configurations & Frequencies
* **LED 1 Frequency**: Configured at 1000 Hz (1 kHz) with 8-bit resolution.
* **LED 2 Frequency**: Configured at 5000 Hz (5 kHz) with 8-bit resolution.
* Both LEDs smoothly fade between minimum and maximum brightness independently.

## Testing & Verification
* **Wokwi Simulation**: Successfully tested and verified independent LED fading behavior on the virtual setup.
* **Physical Hardware**: Verified on the physical ESP32 kit and breadboard with exact visual performance matching the simulation.