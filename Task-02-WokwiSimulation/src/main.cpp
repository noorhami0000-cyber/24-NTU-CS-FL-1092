#include <Arduino.h>

#define LED_PIN 2  // GPIO 2 (Built-in LED)

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH); // Turn LED ON
  delay(1000);                  // Wait 1 second
  digitalWrite(LED_PIN, LOW);  // Turn LED OFF
  delay(1000);                  // Wait 1 second
}







