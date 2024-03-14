#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <Arduino.h>
#include "EventManager.hpp"
#include "definitions.hpp"
#include <Arduino_FreeRTOS.h>
#include <semphr.h>

extern volatile unsigned long blinkInterval;
extern volatile byte currentEvent;
extern volatile byte currentTask;
extern EventManager eventManager;

#endif
