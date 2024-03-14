#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

// LED PINS
#define GREEN_LED_PIN 3
#define INTERMITTENT_LED_PIN 2

// BUTTON PINS
#define RED_BUTTON_PIN 5
#define GREEN_BUTTON_PIN 7
#define BLUE_BUTTON_PIN 6
#define BLACK_BUTTON_PIN 4

// CONSTANTS
const long intervalStep = 100;
const long maxInterval = 2000;
const long defaultInterval = 1000;
const long minInterval = 100;
const int baudRate = 9600;
const int loopDelay = 5; // 5 ms

#define TOGGLE_TASK_DELAY 50
#define DELAY_TASK_DELAY 50
#define IDLE_TASK_DELAY 200
#define RESET_TASK_DELAY 50

// OFFSETS
#define LED_TOGGLE_RECC_OFFSET 2
#define DELAY_CHANGE_RECC_OFFSET 0
#define DELAY_RESET_RECC_OFFSET 1

#define RECC_LED_TOGGLE 1
#define RECC_DELAY_CHANGE 0
#define RECC_RESET_BTN 1

#define PRESCALER_1 (1 << CS10)
#define COMPA_INTERRUPT (1 << OCIE1A)

#endif
