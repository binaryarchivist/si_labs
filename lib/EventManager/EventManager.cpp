#include <Arduino.h>
#include <stdio.h>

#include "EventManager.hpp"
#include "Logger.hpp"

void EventManager::triggerEvent(byte eventType, long count)
{
      if (eventType & EVENT_NONE)
      {
            printf("NONE EVENT\n");
            // Serial.println("NONE EVENT");
      }
      if (eventType & INCREMENT_EVENT)
      {
            printf("Increment event, current count: %ld \r\n", count);
            // Serial.println("INCREMENT_EVENT");

      }
      if (eventType & DECREMENT_EVENT)
      {
            printf("DECREMENT event, current count: %ld \r\n", count);
            // Serial.println("DECREMENT_EVENT");

      }
      if (eventType & TOGGLE_EVENT)
      {
            printf("TOGGLE EVENT\n");
            // Serial.println("TOGGLE_EVENT");
      }
      if (eventType & RESET_EVENT)
      {
            printf("RESET EVENT\n");
            // Serial.println("RESET_EVENT");
      }
}
