#include <Arduino.h>
#include <stdio.h>

#include "EventManager.hpp"

void EventManager::triggerEvent(Event eventType, long count)
{
    if (eventType == EVENT_NONE) return;

    switch (eventType)
    {
    case INCREMENT_EVENT:
        printf("Increment event, current count: %ld \r\n", count);
        break;
    case DECREMENT_EVENT:
        printf("Decrement event, current count: %ld \r\n", count);
        break;
    case RESET_EVENT:
        printf("Reset event \r\n");
        break;
    case TOGGLE_EVENT:
        printf("Toggle Event \r\n");
        break;
    default:
        printf("Unknown Event \r\n");
        break;
    }
}
