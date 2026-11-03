#include <Arduino.h>

#define DAC_PIN 25  // Original ESP32 DAC1 pin[cite: 11]

void setup() {
  Serial.begin(115200);
  Serial.println("DAC LED Fade Test");
}

void loop() {
  // DAC output ko aahista-aahista barhana (0 se 255 tak)[cite: 13]
  for (int value = 0; value <= 255; value++) {
    dacWrite(DAC_PIN, value);
    delay(20);
  }
  
  // DAC output ko aahista-aahista kam karna (255 se 0 tak)[cite: 13]
  for (int value = 255; value >= 0; value--) {
    dacWrite(DAC_PIN, value);
    delay(20);
  }
}