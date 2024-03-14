#include <Arduino.h>

#include "Logger.hpp"

#include "tasks.hpp"
#include "globals.hpp"
#include "definitions.hpp"

int putChar(char c, FILE *f)
{
  return Serial.print(c);
}

int getChar(FILE *f)
{
  while (!Serial.available())
    ;
  return Serial.read();
}

void setupStdio()
{
  Serial.begin(baudRate);
  while (!Serial) ;

  stdin = stdout = fdevopen(Logger::putCharWrapper, Logger::getCharWrapper);
}

void setup()
{
  setupStdio();
  initializeComponents();
  // Serial.begin(9600);
  // printf("test");

  xTaskCreate(toggleTask, "Toggle", 64, nullptr, 1, nullptr);
  xTaskCreate(delayTask, "Delay", 96, nullptr, 2, nullptr);
  xTaskCreate(resetTask, "Reset", 64, nullptr, 1, nullptr);
  xTaskCreate(idleTask, "Idle", 256, nullptr, 1, nullptr);

  vTaskStartScheduler();
}

void loop()
{
}