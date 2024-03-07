#include <Arduino.h>
#include <stdio.h>

#include "EventManager.hpp"
#include "Logger.hpp"

void EventManager::triggerEvent(Event eventType, long count)
{
    if (eventType == EVENT_NONE) return;

    switch (eventType)
    {
    case INCREMENT_EVENT:
        Logger::getInstance()->clearScreen();
        printf("Increment event, current count: %ld \r\n", count);
        break;
    case DECREMENT_EVENT:
        Logger::getInstance()->clearScreen();
        printf("Decrement event, current count: %ld \r\n", count);
        break;
    case RESET_EVENT:
        Logger::getInstance()->clearScreen();
        printf("Reset event \r\n");
        break;
    case TOGGLE_EVENT:
        Logger::getInstance()->clearScreen();
        printf("Toggle Event \r\n");
        break;
    default:
        Logger::getInstance()->clearScreen();
        printf("Unknown Event \r\n");
        break;
    }
}
