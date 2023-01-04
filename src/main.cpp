/**
 * @file main.cpp
 * @author duo
 * @brief environmental monitor based around an m5stack
 * @version 0.1
 * @date 2022-12-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * m5Fire-TempSensor
 * 
 * This is a basic program to poll data from a DHT-22 temperature/humidity sensor module and display it on the LCD
 * 
 * 
*/

#include <string>
#include <Arduino.h>
#include <M5Stack.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN 36
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

int chk;
float humidity;     //humidity value read from sensor
float temperature;  //temperature value read from sensor


void setup() {
  //Initialize LCD, DHT sensor
  M5.begin(true,false,true,true);
  M5.Power.begin();
  M5.Lcd.begin();
  M5.Lcd.clearDisplay(BLACK);
  dht.begin();
  M5.Lcd.drawString("Humidity", 50, 70);
  M5.Lcd.drawString("Temperature", 100, 70);

}

void loop() {
  // count millis, update LCD 250ms, update DHT22 2000ms
  sleep(2);
  
  humidity = dht.readHumidity(false);
  temperature = dht.readTemperature(true,false);
  
  //M5.Lcd.drawString(String(humidity), 50, 50);
  //M5.Lcd.drawString(String(temperature), 100, 50);
  M5.Lcd.setCursor(50, 50);
  M5.Lcd.print(humidity);
  M5.Lcd.setCursor(100, 50);
  M5.Lcd.print(temperature);
  
  M5.Lcd.drawRect(25,50,10,10,RED);
  sleep(1);
  M5.Lcd.drawRect(25,50,10,10,BLACK);
  //M5.Lcd.draw
}
