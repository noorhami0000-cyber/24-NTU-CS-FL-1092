#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int BUTTON_PIN = 18;
int pressCount = 0;
int lastButtonState = HIGH;
int buttonState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  Serial.begin(115200);
  
  Wire.begin(21, 22);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("IoT HW-01 Ready"));
  display.display();
  delay(1500);
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW) {
        pressCount++;
        Serial.print("Button Pressed! Count: ");
        Serial.println(pressCount);
      }
    }
  }

  lastButtonState = reading;

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(F("ESP32 OLED Status"));
  
  display.setCursor(0, 20);
  display.print(F("Status: "));
  display.println(buttonState == LOW ? F("PRESSED") : F("RELEASED"));

  display.setCursor(0, 40);
  display.print(F("Press Count: "));
  display.println(pressCount);
  
  display.display();
}