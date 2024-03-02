#include "Button.hpp"
#include <Arduino.h>

// BUTTON CONSTANTS
#define INITIAL_DEBOUNCE_DELAY 50

Button::Button() = default;

Button::Button(int pin, void (*onClickCallback)()) : buttonPin(pin), callback(onClickCallback), lastButtonState(LOW), currentButtonState(LOW), lastDebounceTime(0), debounceDelay(INITIAL_DEBOUNCE_DELAY)
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
