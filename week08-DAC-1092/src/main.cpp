// Name: Shahnoor Zahid
// Task 25: DAC2 on GPIO26
#include <Arduino.h>

#define DAC_PIN 26  // Yahan GPIO26 kar diya hai

void setup()
{
    Serial.begin(115200);
    Serial.println("Task 25: DAC2 GPIO26 Test");
}

void loop()
{
    for (int value = 0; value <= 255; value++)
    {
        dacWrite(DAC_PIN, value);
        delay(20);
    }
    
    for (int value = 255; value >= 0; value--)
    {
        dacWrite(DAC_PIN, value);
        delay(20);
    }
}