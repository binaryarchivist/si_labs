#include "Button.hpp"
#include <Arduino.h>

Button::Button(int pin, void (*onClickCallback)()) : buttonPin(pin), callback(onClickCallback), lastButtonState(LOW), currentButtonState(LOW), lastDebounceTime(0), debounceDelay(50)
{
  pinMode(pin, INPUT_PULLUP);
}

void Button::checkForClick()
{
  bool reading = digitalRead(buttonPin);
  if (reading != lastButtonState)
  {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    if (reading != currentButtonState)
    {
      currentButtonState = reading;

      if (currentButtonState == LOW)
      {
        if (callback != nullptr)
        {
          callback();
        }
      }
    }
  }

  lastButtonState = reading;
}
