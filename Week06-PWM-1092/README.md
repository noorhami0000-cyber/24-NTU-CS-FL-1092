//Shahnoor Zahid
//24-NTU-CS-FL-1092
ESP32 PWM LED Fade

Project Overview:
This project demonstrates Pulse Width Modulation (PWM) using an ESP32 microcontroller. The external LED gradually becomes brighter and then dimmer.

Components Required

- ESP32 development board
- Red LED
- 220-ohm resistor
- Breadboard and jumper wires
- USB cable

Wiring

- ESP32 GPIO 4 → 220-ohm resistor
- Resistor → LED anode (long leg)
- LED cathode (short leg) → ESP32 GND

PWM Configuration

- PWM frequency: 5000 Hz
- PWM resolution: 8 bits
- Duty cycle range: 0–255
- LED pin: GPIO 4

Working Principle

The program gradually increases the PWM duty cycle from 0 to 255, making the LED brighter. It then decreases the duty cycle from 255 to 0, making the LED dimmer. This process repeats continuously.

Software and Tools

- Visual Studio Code
- PlatformIO
- Wokwi Simulator
- Arduino framework for ESP32

How to Run

1. Open the project in Visual Studio Code.
2. Build the project using PlatformIO.
3. Start the Wokwi simulation or upload the firmware to the ESP32.
4. Observe the LED fading in and out.

Expected Result

The LED continuously fades from dim to bright and from bright to dim.