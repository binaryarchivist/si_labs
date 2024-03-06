#include "Tasks.hpp"

Button redButton;
Button blueButton;
Button greenButton;
Button blackButton;

LED greenLed;
LED intermittendLED;

void handleDelayTask()
{
    redButton.checkForClick();
    blueButton.checkForClick();
    static unsigned long lastToggleTime;

    if ((millis() - lastToggleTime < blinkInterval) || greenLed.getState())
    {
        return;
    }
    intermittendLED.toggle();
    lastToggleTime = millis();
}

void handleReset()
{
    currentEvent = RESET_EVENT;

    intermittendLED.turnOff();
    greenLed.turnOn();

    blinkInterval = defaultInterval;
}

void onToggleTask()
{
    currentEvent = TOGGLE_EVENT;

    if (greenLed.getState())
        greenLed.turnOff();
    intermittendLED.turnOn();
}

void handleResetTask()
{
    blackButton.checkForClick();
}

void handleToggleTask()
{
    greenButton.checkForClick();
}

void initializeComponents()
{
    redButton = Button(RED_BUTTON_PIN, handleIncrementTask);
    blueButton = Button(BLUE_BUTTON_PIN, handleDecrementTask);
    greenButton = Button(GREEN_BUTTON_PIN, onToggleTask);
    blackButton = Button(BLACK_BUTTON_PIN, handleReset);

    greenLed = LED(GREEN_LED_PIN);
    intermittendLED = LED(INTERMITTENT_LED_PIN);

    greenLed.turnOn();
    intermittendLED.turnOff();
}
