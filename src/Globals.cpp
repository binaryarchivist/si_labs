#include "globals.hpp"

volatile unsigned long blinkInterval = defaultInterval;
volatile byte currentTask = NONE;
volatile byte currentEvent = EVENT_NONE;
EventManager eventManager = EventManager();

