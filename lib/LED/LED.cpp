#include "Led.hpp"
#include <Arduino.h>

LED::LED(int pinNumber) : pin(pinNumber), state(LOW)
{
  pinMode(pin, OUTPUT);
}

void LED::turn(bool mode)
{
  digitalWrite(pin, mode ? HIGH : LOW);
  state = mode;
}
