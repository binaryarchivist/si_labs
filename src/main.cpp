#include <Arduino.h>

#include "Button.hpp"

#define RED_BUTTON_PIN 5

void myFunction() {
  Serial.println("Clicked Red !");
}

Button redButton(RED_BUTTON_PIN, myFunction);

void setup() {
  Serial.begin(9600);
  Serial.println("Test Serial");
}

void loop() {
  redButton.checkForClick();
}