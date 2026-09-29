#include <Arduino.h>

const int buttonPin = 36;   // Button pin
const int ledPin = 2;       // First LED pin
const int led2Pin = 5;      // Second LED pin

int buttonState = 0;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() 
{
  buttonState = digitalRead(buttonPin);

  // INPUT_PULLUP mein Button dabane par LOW milta hai
  if (buttonState == LOW) { 
    digitalWrite(ledPin, HIGH);
    digitalWrite(led2Pin, LOW);
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(led2Pin, HIGH);
  }
}