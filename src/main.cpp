#include <Arduino.h>

#include "Tasks.hpp"
#include "Globals.hpp"

void setup() {
  Serial.begin(9600);
  initializeComponents();
  setTimerConfiguration();
}

void loop() {
  Serial.println("Loop");
  delay(10000);
}