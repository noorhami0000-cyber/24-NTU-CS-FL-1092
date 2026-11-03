// Name: Shahnoor Zahid
// Task 24: Fade with different delays
#include <Arduino.h>

#define DAC_PIN 25

void setup()
{
    Serial.begin(115200);
    Serial.println("Task 24: Delay Test");
}

void loop()
{
    // Increase DAC output (delay 5ms for fast fade)
    for (int value = 0; value <= 255; value++)
    {
        dacWrite(DAC_PIN, value);
        delay(5); // Yahan delay change kiya hai
    }

    // Decrease DAC output (delay 50ms for slow fade)
    for (int value = 255; value >= 0; value--)
    {
        dacWrite(DAC_PIN, value);
        delay(50); // Yahan delay change kiya hai
    }
}