
# Homework 2 — Dual PWM, OLED & GitHub Submission

**Course:** Embedded IoT Systems
**Student Name:** Shahnoor Zahid
**Registration ID:** 24-NTU-CS-FL-1092
**Board:** ESP32 DevKit V1

## 1. Project Overview

This project implements dual-LED brightness control using Pulse Width Modulation (PWM) on the ESP32. Two LEDs operate at different PWM frequencies, while an SSD1306 I²C OLED display shows their duty-cycle percentages and configured frequencies.

The assignment is divided into two tasks:

- **Task 1 — Dual PWM:** Control two LEDs independently using different PWM frequencies and demonstrate a fading effect.
- **Task 2 — OLED Monitoring:** Display the live duty-cycle percentages and configured PWM frequencies of both LEDs on an SSD1306 OLED.

## 2. Hardware and Wiring

### Task 1 — Dual LED PWM

Each LED is connected to a separate ESP32 GPIO pin through a 220Ω current-limiting resistor.

| Component              | ESP32 Pin | Configured PWM Frequency |
| ---------------------- | --------- | ------------------------ |
| LED 1 (Red)            | GPIO 18   | 1000 Hz (1 kHz)          |
| LED 2 (Green)          | GPIO 19   | 5000 Hz (5 kHz)          |
| LED ground connections | GND       | Common ground            |

The current-limiting resistors help protect the LEDs by limiting current. The ESP32 generates PWM signals on GPIO 18 and GPIO 19 to control their brightness.

### Task 2 — OLED Connections

The SSD1306 OLED communicates with the ESP32 using the I²C protocol.

| OLED Pin | ESP32 Connection |
| -------- | ---------------- |
| SDA      | GPIO 21          |
| SCL      | GPIO 22          |
| VCC      | 3.3V             |
| GND      | GND              |

The OLED resolution is 128 × 64 pixels, and its configured I²C address is `0x3C`.

## 3. PWM Frequencies and Resolution

Pulse Width Modulation (PWM) controls the average power delivered to an LED by switching its output ON and OFF rapidly.

The project uses these configured settings:

- **LED 1:** GPIO 18, frequency 1000 Hz (1 kHz).
- **LED 2:** GPIO 19, frequency 5000 Hz (5 kHz).
- **PWM resolution:** 8 bits.

Different PWM frequencies are configured for the two LEDs as required by the assignment.

## 4. Duty-Cycle Control

Duty cycle is the percentage of each PWM period during which the signal remains ON. It affects the apparent brightness of an LED.

With 8-bit PWM resolution, the duty-cycle value ranges from 0 to 255.

**Formula:**

Duty Cycle (%) = (PWM Value / 255) × 100

| PWM Value | Approximate Duty Cycle | Expected LED Behaviour |
| --------: | ---------------------: | ---------------------- |
|         0 |                     0% | OFF                    |
|        64 |                    25% | Dim                    |
|       128 |                    50% | Medium brightness      |
|       191 |                    75% | Bright                 |
|       255 |                   100% | Maximum brightness     |

The program increases and decreases the duty-cycle values to create a continuous fading effect. Both LEDs are controlled independently.

## 5. OLED Output

In Task 2, the SSD1306 OLED displays the duty-cycle percentage and configured PWM frequency for each LED.

The display provides the following information:

- LED 1 duty-cycle percentage.
- LED 1 configured frequency: 1000 Hz.
- LED 2 duty-cycle percentage.
- LED 2 configured frequency: 5000 Hz.

As the LEDs fade, their duty-cycle percentages change. The configured frequencies remain constant, and the OLED refreshes periodically to provide live monitoring.

## 6. Testing and Results

### Wokwi Simulation

The project was tested in the Wokwi simulator.

- The LED fading behaviour was checked.
- The two different PWM frequencies were configured.
- The OLED output was checked for duty-cycle percentages and configured frequencies.

### Physical Hardware Testing

The project was also tested on a physical ESP32 DevKit V1 with a breadboard, LEDs, current-limiting resistors, and OLED display.

- Both LED outputs were checked on the physical circuit.
- The LED fading behaviour was observed as the duty-cycle values changed.
- The configured PWM frequencies were checked during testing.
- The OLED output was checked against the programmed duty-cycle percentages and frequency settings.

## 7. Project Links

- **GitHub Repository:** **GitHub repository: [https://github.com/noorhami0000-cyber/24-NTU-CS-FL-1092](https://github.com/noorhami0000-cyber/24-NTU-CS-FL-1092)**

**Wokwi project: [https://wokwi.com/projects/478512492516691969](https://wokwi.com/projects/478512492516691969)**

### **8. Conclusion**

This project demonstrates dual-LED brightness control using PWM on the ESP32 with two different configured frequencies. The SSD1306 OLED provides live duty-cycle and frequency information. The implementation was tested in Wokwi and on physical hardware.

