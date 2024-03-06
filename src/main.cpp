#include <Arduino.h>

#include "Globals.hpp"
#include "Definitions.hpp"
#include "Logger.hpp"

#include "tasks.hpp"
#include "timer.hpp"

void setup() {
  Logger::getInstance();
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