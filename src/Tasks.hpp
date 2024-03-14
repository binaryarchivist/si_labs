#ifndef TASKS_HPP
#define TASKS_HPP

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>
#include "Button.hpp"
#include "LED.hpp"
#include "definitions.hpp"
#include "globals.hpp"

void handleReset();
void handleToggle();
void handleIncrement();
void handleDecrement();

void idleTask(void* params);
void resetTask(void* params);
void delayTask(void* params);
void toggleTask(void* params);

void initializeComponents();

#endif
