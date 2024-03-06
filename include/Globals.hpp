#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <Arduino.h>
#include "EventManager.hpp"
#include "definitions.hpp"

extern volatile unsigned long blinkInterval;
extern Event currentEvent;
extern volatile byte currentTask;
extern EventManager eventManager;

void idleTask();
void handleIncrementTask();
void handleDecrementTask();

#endif
