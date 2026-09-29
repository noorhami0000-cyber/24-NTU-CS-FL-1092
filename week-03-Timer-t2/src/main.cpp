// Week3-Lecture2
// Timer Interrupt (Internal)
// Embedded IoT System Fall-2026

// Name: Shahnoor Zahid           Reg#: 24-NTU-CS-FL-1092

#include <Arduino.h>

#define LED 4
#define BUTTON_PIN 35

hw_timer_t *My_timer = NULL;

void ARDUINO_ISR_ATTR onTimer() {           // ARDUINO_ISR_ATTR == IRAM_ATTR
  digitalWrite(LED, !digitalRead(LED));     // safe in ISR on ESP32
}

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // 1 MHz timer tick (1 tick = 1 us)
  My_timer = timerBegin(1000000);

  // attach ISR
  timerAttachInterrupt(My_timer, &onTimer);

  // call ISR every 1,000,000 us (1 second)
  timerAlarm(My_timer, 1000000, true, 0);
}

void loop() {
  // Button check: Jab tak button press rehta hai, timer pause / handle hoga
  if (digitalRead(BUTTON_PIN) == LOW) {
    timerStop(My_timer);       // Button press par timer pause
  } else {
    timerStart(My_timer);      // Button release par timer active
  }
}