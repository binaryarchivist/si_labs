#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include "EventManager.hpp"
#include "Definitions.hpp"

volatile unsigned long blinkInterval = defaultInterval;
Event currentEvent = EVENT_NONE;
volatile byte currentTask = NONE;
EventManager eventManager = EventManager();

void idleTask()
{
    eventManager.triggerEvent(currentEvent, blinkInterval);
    currentEvent = EVENT_NONE;
}

void handleIncrementTask()
{
    currentEvent = INCREMENT_EVENT;
    if (blinkInterval + intervalStep <= maxInterval)
    {
        blinkInterval += intervalStep;
    }
}

void handleDecrementTask()
{
    currentEvent = DECREMENT_EVENT;
    if (blinkInterval - intervalStep >= minInterval)
    {
        blinkInterval -= intervalStep;
    }
}

#endif