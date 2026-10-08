// Week3-Lecture2
// Timer Interrupt (Internal) with Push Button
// Embedded IoT System Fall-2026
// Name: Shahnoor Zahid           Reg#: 24-NTU-CS-FL-1092
#include <Arduino.h>

#define LED 2
#define BUTTON_PIN 35

hw_timer_t *My_timer = NULL;
volatile bool isBlinking = false;
volatile int blinkCount = 0;
const int maxBlinks = 10; // Button dabane par LED 5 baar ON-OFF (10 toggles) hogi

// Timer ISR: Jab timer trigger hoga yeh function chalega
void IRAM_ATTR onTimer() {
  if (isBlinking) {
    digitalWrite(LED, !digitalRead(LED)); // Toggle LED
    blinkCount++;
    
    // Jab required seconds/blinks poore ho jayen toh stop kar do
    if (blinkCount >= maxBlinks) {
      isBlinking = false;
      digitalWrite(LED, LOW); // LED ko OFF kar do
      timerAlarmDisable(My_timer); // Timer stop
    }
  }
}

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // ESP32 Core v2.x Syntax
  My_timer = timerBegin(0, 80, true);
  timerAttachInterrupt(My_timer, &onTimer, true);
  
  // Timer Alarm set for 500,000 us (0.5 second speed)
  timerAlarmWrite(My_timer, 500000, true);
}

void loop() {
  // Push Button Check (INPUT_PULLUP mein press hone par LOW milta hai)
  if (digitalRead(BUTTON_PIN) == LOW && !isBlinking) {
    delay(50); // Debounce delay
    if (digitalRead(BUTTON_PIN) == LOW) {
      blinkCount = 0;
      isBlinking = true;
      timerWrite(My_timer, 0);       // Timer reset
      timerAlarmEnable(My_timer);    // Timer Start
    }
  }
}