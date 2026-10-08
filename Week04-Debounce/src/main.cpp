/**
 * =====================================================================
 * @file main.cpp
 * @author Shahnoor Zahid
 * @roll_number 24-NTU-CS-FL-1092
 * @course CSE-3079 Embedded IoT Systems - Week 4 Practical Task
 * @description Timer-Based Non-Blocking Button Debouncing on ESP32 (Arduino-ESP32 3.x API)
 * =====================================================================
 */

#include <Arduino.h>

#define BUTTON_PIN 4    
#define LED_PIN 2      


hw_timer_t *debounceTimer = NULL;
volatile bool ledState = LOW;


void ARDUINO_ISR_ATTR onDebounceTimer()
{
    
    if (digitalRead(BUTTON_PIN) == LOW)
    {
        ledState = !ledState;
        digitalWrite(LED_PIN, ledState);
    }
}


void ARDUINO_ISR_ATTR onButtonISR()
{
    timerWrite(debounceTimer, 0);
    timerAlarm(debounceTimer, 50000, false, 0);
}

void setup()
{
    pinMode(BUTTON_PIN, INPUT_PULLUP); 
    pinMode(LED_PIN, OUTPUT);          
    digitalWrite(LED_PIN, LOW);

   
    debounceTimer = timerBegin(1000000); 
    timerAttachInterrupt(debounceTimer, &onDebounceTimer);

   
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), onButtonISR, FALLING);
}

void loop()
{
    // Main loop - do nothing
}