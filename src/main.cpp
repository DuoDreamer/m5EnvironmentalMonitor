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

#include <Arduino.h>
#include <M5Stack.h>

void setup() {
  //Initialize M5stack device, initialize sensors
  M5.begin(true,true,true,true);
  M5.Power.begin();



}

void loop() {
  //query sensors and update LCD every few seconds
  
}