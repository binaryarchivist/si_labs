#include <Arduino.h>

#include "Tasks.hpp"
#include "Globals.hpp"
#include "Definitions.hpp"

void setup() {
  Serial.begin(baudRate);
  initializeComponents();
  setTimerConfiguration();
}

void loop() {
  Serial.println("Loop");
  delay(loopDelay);
}