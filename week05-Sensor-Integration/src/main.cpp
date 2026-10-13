/*
  Name: Shahnoor Zahid
  Reg.Number: 24-NTU-CS-FL-1092
  Week 5: I2C OLED & DHT11 Sensor Integration
*/

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C

#define DHT_PIN 14
#define DHT_TYPE DHT11

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(115200);
  
  // Custom I2C Pins for ESP32
  Wire.begin(21, 22);

  // Initialize DHT Sensor
  dht.begin();

  // Initialize SSD1306 OLED Display
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Infinite Trap on Failure
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Week 5: IoT System"));
  display.println(F("Initializing..."));
  display.display();
  delay(2000);
}

void loop() {
  // Read Humidity and Temperature
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Validation Guard for Corrupted/Failed Readings
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println(F("SENSOR ERROR!"));
    display.println(F("Check DHT11 Wiring"));
    display.display();
    delay(2000);
    return;
  }

  // Serial Monitor Telemetry Output
  Serial.print(F("Humidity: "));
  Serial.print(humidity, 1);
  Serial.print(F("%  Temperature: "));
  Serial.print(temperature, 1);
  Serial.println(F("C"));

  // OLED Visual UI Rendering
  display.clearDisplay();
  
  // Header
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(F("ENVIRONMENT MONITOR"));
  display.drawLine(0, 10, 127, 10, SSD1306_WHITE);

  // Temperature Display Block
  display.setCursor(0, 20);
  display.print(F("Temp: "));
  display.setTextSize(2);
  display.setCursor(40, 18);
  display.print(temperature, 1);
  display.setTextSize(1);
  display.print(F(" C"));

  // Humidity Display Block
  display.setCursor(0, 45);
  display.print(F("Hum:  "));
  display.setTextSize(2);
  display.setCursor(40, 43);
  display.print(humidity, 1);
  display.setTextSize(1);
  display.print(F(" %"));

  // Push Buffer to Physical OLED Matrix
  display.display();

  // Respect DHT11 1Hz Sampling Rate Limit (Wait 2 Seconds)
  delay(2000);
}