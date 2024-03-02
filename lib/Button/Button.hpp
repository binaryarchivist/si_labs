#ifndef Button_HPP
#define Button_HPP

class Button
{
private:
  int buttonPin;
  bool lastButtonState;
  bool currentButtonState;
  unsigned long lastDebounceTime;
  unsigned long debounceDelay;
  void (*callback)();

public:
  Button(int pin, void (*onClickCallback)());
  void checkForClick();
};

#endif