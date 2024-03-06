#ifndef TIMER_CONFIGURATION_HPP
#define TIMER_CONFIGURATION_HPP

#include <Arduino.h>

#include "definitions.hpp"
#include "globals.hpp"

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
        recToggleLed = RECC_LED_TOGGLE;
        currentTask |= TOGGLE;
    }

    if (--recChangeDelay <= 0)
    {
        recChangeDelay = RECC_DELAY_CHANGE;
        currentTask |= DELAY;
    }

     if (--recReset <= 0)
    {
        recReset = RECC_RESET_BTN;
        currentTask |= RESET;
    }
    currentTask |= IDLE;
}

#endif