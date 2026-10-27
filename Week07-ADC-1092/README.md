# ESP32 LDR Sensor and OLED Display Project

This project is an IoT-based embedded system built using PlatformIO and the Arduino framework for the ESP32 microcontroller. It measures ambient light intensity using an LDR (Light Dependent Resistor) sensor, calculates the voltage, and displays the real-time readings on a 0.96-inch SSD1306 OLED display as well as the Serial Monitor.

## Student Details
* **Name:** Shahnoor Zahid
* **Roll Number:** 1092
* **Course:** Internet of Things (IoT) / Embedded Systems

---

## Components Required
1. ESP32 DevKit V1 Board
2. 0.96-inch SSD1306 OLED Display (I2C)
3. LDR (Photoresistor) Sensor
4. 10k resistor (for voltage divider circuit)
5. Breadboard and Jumper Wires
6. Micro-USB Cable

---

## Circuit Connections

| Component | Pin | ESP32 Pin | Description |
| :--- | :--- | :--- | :--- |
| **OLED Display** | VCC | 3.3V | Power Supply |
| | GND | GND | Ground |
| | SDA | GPIO 21 | I2C Data Line |
| | SCL | GPIO 22 | I2C Clock Line |
| **LDR Sensor** | VCC | 3.3V | Power Supply |
| | GND | GND | Ground |
| | AO | GPIO 34 | Analog ADC Input |

---

## Code Description (`src/main.cpp`)
* **Startup Splash Screen:** When the ESP32 powers on, the OLED display shows the author's name ("Shahnoor Zahid") and roll number ("1092") for 3 seconds.
* **Sensor Monitoring:** After the splash screen, the system continuously reads the analog value from the LDR connected to pin 34, converts it into voltage (0V to 3.3V), and updates both the OLED display and Serial Monitor every second.

---

## How to Run the Project

### 1. In Wokwi Simulator (VS Code)
* Open the project folder in Visual Studio Code.
* Make sure the Wokwi Simulator extension is installed.
* Build the project (`Ctrl + Alt + B`).
* Open the Command Palette (`Ctrl + Shift + P`) and select **Wokwi: Start Simulator**.

### 2. On Physical Hardware
* Connect the ESP32 to your PC using a USB cable.
* Assemble the circuit on a breadboard according to the connection table.
* Click the **Upload** button in PlatformIO to flash the code to the ESP32 board.
* Open the Serial Monitor at a baud rate of `115200` to view the live sensor output.