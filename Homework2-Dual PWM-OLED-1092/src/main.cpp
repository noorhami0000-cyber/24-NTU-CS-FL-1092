#include <Arduino.h>

// Pin definitions for Task 1
const int LED1_PIN = 18;
const int LED2_PIN = 19;

// Different PWM frequencies for Task 1 (Requirement: Different frequencies)
const int FREQ_LED1 = 1000; // 1 kHz
const int FREQ_LED2 = 5000; // 5 kHz

// PWM Resolution (8-bit: 0 to 255)
const int RESOLUTION = 8; 

// Duty cycle variables (kept accessible for Task 2 OLED monitoring)
int dutyCycle1 = 0;
int dutyCycle2 = 255;
int step1 = 5;
int step2 = -5;

void setup() {
  Serial.begin(115200);

  // Configure LEDC PWM channels for ESP32
  ledcAttach(LED1_PIN, FREQ_LED1, RESOLUTION);
  ledcAttach(LED2_PIN, FREQ_LED2, RESOLUTION);
}

void loop() {
  // Update LED 1 duty cycle (Smooth fading)
  dutyCycle1 += step1;
  if (dutyCycle1 <= 0 || dutyCycle1 >= 255) {
    step1 = -step1;
  }

  // Update LED 2 duty cycle (Smooth fading inverse)
  dutyCycle2 += step2;
  if (dutyCycle2 <= 0 || dutyCycle2 >= 255) {
    step2 = -step2;
  }

  // Apply PWM values to pins
  ledcWrite(LED1_PIN, dutyCycle1);
  ledcWrite(LED2_PIN, dutyCycle2);

  delay(50);
}