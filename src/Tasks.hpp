#ifndef TASKS_HPP
#define TASKS_HPP

#include <Arduino.h>
#include "Button.hpp"
#include "LED.hpp"
#include "Definitions.hpp"
#include "Globals.hpp"

void handleDelayTask();
void handleReset();
void onToggleTask();
void handleResetTask();
void handleToggleTask();
void initializeComponents();

#endif
