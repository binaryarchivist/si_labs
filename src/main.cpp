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
  if (currentTask & IDLE) {
    idleTask();
  }
  if (currentTask & DELAY) {
    handleDelayTask();
  }
  if (currentTask & RESET) {
    handleResetTask();
  }
  if (currentTask & TOGGLE) {
    handleToggleTask();
  }
  currentTask = NONE;
  delay(loopDelay);
}