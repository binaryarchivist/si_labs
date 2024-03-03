#include "EventManager.hpp"
#include <Arduino.h>

void EventManager::triggerEvent(Event eventType, long count)
{
    if (eventType == EVENT_NONE) return;

    switch (eventType)
    {
    case INCREMENT_EVENT:
        Serial.print("Increment event, current count: ");
        Serial.println(count);
        break;
    case DECREMENT_EVENT:
        Serial.print("Decrement event, current count: ");
        Serial.println(count);
        break;
    case RESET_EVENT:
        Serial.println("Reset event");
        break;
    case TOGGLE_EVENT:
        Serial.println("Toggle Event");
        break;
    default:
        Serial.println("Unknown Event");
        break;
    }
}
