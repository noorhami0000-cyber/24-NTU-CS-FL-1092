# Homework 2: Dual-LED PWM Control with OLED Monitoring

## Overview
* This project is the final implementation of Embedded IoT Systems Homework 2.
* It controls two independent LEDs fading at different PWM frequencies (1 kHz and 5 kHz) on an ESP32.
* Live duty cycle percentages and operating frequencies are continuously displayed on an SSD1306 I2C OLED screen.

## Hardware & Pin Wiring
* **LED 1 (Red)**: Connected to **GPIO 18** via 220Ω resistor.
* **LED 2 (Green)**: Connected to **GPIO 19** via 220Ω resistor.
* **SSD1306 OLED (I2C)**:
  * SDA -> **GPIO 21**
  * SCL -> **GPIO 22**
  * VCC -> **3.3V**
  * GND -> **GND**

## PWM Configurations
* **LED 1**: Frequency = 1000 Hz (1 kHz), Resolution = 8-bit.
* **LED 2**: Frequency = 5000 Hz (5 kHz), Resolution = 8-bit.

## Testing & Results
* **Wokwi Simulation**: Verified smooth LED fading with real-time duty cycle updates on the virtual OLED screen.
* **Physical Hardware**: Tested on physical ESP32 DevKit V1 with exact hardware response matching simulation.