#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define LDR_PIN 34
#define SDA_PIN 21
#define SCL_PIN 22
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  // --- Startup Splash Screen (Name & Roll Number) ---
  display.setTextSize(1);
  display.setCursor(15, 20);
  display.println("Shahnoor Zahid");
  display.setCursor(35, 40);
  display.println("1092");
  display.display();
  
  delay(3000); 
}

void loop() {
  int adcValue = analogRead(LDR_PIN);
  float voltage = (adcValue / 4095.0) * 3.3;

  // --- LDR Readings Screen with Proper Spacing ---
  display.clearDisplay();
  display.setTextSize(1);
  
  // Pehli line (LDR ADC) uper ki taraf
  display.setCursor(0, 2);
  display.print("LDR ADC: "); 
  display.print(adcValue);

  // Doosri line (Voltage) thoda neechay gap de kar
  display.setCursor(0, 24);
  display.print("Voltage: "); 
  display.print(voltage, 2); 
  display.print(" V");

  display.display();

  Serial.printf("ADC: %d  |  Voltage: %.2f V\n", adcValue, voltage);
  
  delay(1000);
}