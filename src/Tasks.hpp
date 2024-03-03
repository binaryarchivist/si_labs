#pragma once

#ifndef Tasks_HPP
#define Tasks_HPP

#include "Button.hpp"
#include "LED.hpp"

#include "Definitions.hpp"
#include "Globals.hpp"

Button redButton;
Button blueButton;
Button greenButton;
Button blackButton;

LED greenLed;
LED intermittendLED;

void handleReset();
void handleToggleTask();

void initializeComponents()
{
    // Instantiate Buttons
    redButton = Button(RED_BUTTON_PIN, handleIncrementTask);
    blueButton = Button(BLUE_BUTTON_PIN, handleDecrementTask);
    greenButton = Button(GREEN_BUTTON_PIN, handleToggleTask);
    blackButton = Button(BLACK_BUTTON_PIN, handleReset);

    // Instantiate LEDs
    greenLed = LED(GREEN_LED_PIN);
    intermittendLED = LED(INTERMITTENT_LED_PIN);

    // Default State
    greenLed.turnOn();
    intermittendLED.turnOff();
}

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

void handleToggleTask()
{
    currentEvent = TOGGLE_EVENT;

    if (greenLed.getState())
        greenLed.turnOff();
    intermittendLED.turnOn();
}

void setTimerConfiguration()
{
    OCR1A = 16000;
    TCCR1A = 0;
    TCCR1B = 0;
    TCCR1B |= PRESCALER_1;
    TIMSK1 |= COMPA_INTERRUPT;
}

ISR(TIMER1_COMPA_vect)
{
    static int recToggleLed = LED_TOGGLE_RECC_OFFSET;
    static int recChangeDelay = DELAY_CHANGE_RECC_OFFSET;
    static int recReset = DELAY_RESET_RECC_OFFSET;

    OCR1A += 8000;

    if (--recToggleLed <= 0)
    {
        greenButton.checkForClick();
        recToggleLed = RECC_LED_TOGGLE;
    }

    if (--recChangeDelay <= 0)
    {
        handleDelayTask();
        recChangeDelay = RECC_DELAY_CHANGE;
    }

     if (--recReset <= 0)
    {
        blackButton.checkForClick();
        recReset = RECC_RESET_BTN;
    }

    idleTask();
}

#endif