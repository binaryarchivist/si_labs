#include "Led.hpp"
#include <Arduino.h>

LED::LED() = default;

LED::LED(int pinNumber) : pin(pinNumber)
{
  pinMode(pin, OUTPUT);
}

void LED::turnOn()
{
  digitalWrite(pin, HIGH);
}

void LED::turnOff()
{
  digitalWrite(pin, LOW);
}

bool LED::getState()
{
  return digitalRead(pin);
}

void LED::toggle()
{
  if (getState())
  {
    turnOff();
    return;
  }
  turnOn();
}
