#include <Arduino.h>

const int LED_PIN = 4;

const int PWM_FREQUENCY = 5000;
const int PWM_RESOLUTION = 8;
const int PWM_MAX_DUTY = 255;

void setup() {
    Serial.begin(115200);

    bool success = ledcAttach(
        LED_PIN,
        PWM_FREQUENCY,
        PWM_RESOLUTION
    );

    if (success) {
        Serial.println("PWM started successfully!");
    } else {
        Serial.println("PWM attach failed!");
    }
}

void loop() {
    // LED gradually becomes brighter
    for (int duty = 0; duty <= PWM_MAX_DUTY; duty++) {
        ledcWrite(LED_PIN, duty);
        delay(10);
    }

    // LED gradually becomes dimmer
    for (int duty = PWM_MAX_DUTY; duty >= 0; duty--) {
        ledcWrite(LED_PIN, duty);
        delay(10);
    }
}