#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int LED1_PIN = 18;
const int LED2_PIN = 19;

const int FREQ_LED1 = 1000; // 1 kHz
const int FREQ_LED2 = 5000; // 5 kHz
const int RESOLUTION = 8; 

int dutyCycle1 = 0;
int dutyCycle2 = 255;
int step1 = 5;
int step2 = -5;

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
  display.display();

  ledcAttach(LED1_PIN, FREQ_LED1, RESOLUTION);
  ledcAttach(LED2_PIN, FREQ_LED2, RESOLUTION);
}

void loop() {
  dutyCycle1 += step1;
  if (dutyCycle1 <= 0 || dutyCycle1 >= 255) {
    step1 = -step1;
  }

  dutyCycle2 += step2;
  if (dutyCycle2 <= 0 || dutyCycle2 >= 255) {
    step2 = -step2;
  }

  ledcWrite(LED1_PIN, dutyCycle1);
  ledcWrite(LED2_PIN, dutyCycle2);

  int percent1 = (dutyCycle1 * 100) / 255;
  int percent2 = (dutyCycle2 * 100) / 255;

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  
  display.setCursor(0, 0);
  display.println(F("PWM MONITOR (HW-2)"));
  display.drawLine(0, 10, 128, 10, SSD1306_WHITE);

  display.setCursor(0, 16);
  display.print(F("LED1: "));
  display.print(percent1);
  display.println(F("%"));

  display.setCursor(0, 28);
  display.print(F("F: "));
  display.print(FREQ_LED1);
  display.println(F(" Hz"));

  display.setCursor(0, 42);
  display.print(F("LED2: "));
  display.print(percent2);
  display.println(F("%"));

  display.setCursor(0, 54);
  display.print(F("F: "));
  display.print(FREQ_LED2);
  display.println(F(" Hz"));

  display.display();

  delay(50);
}