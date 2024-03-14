#include "Tasks.hpp"
#include "globals.hpp"
#include <Arduino_FreeRTOS.h>
#include <semphr.h>

Button redButton;
Button blueButton;
Button greenButton;
Button blackButton;

LED greenLed;
LED intermittendLED;

SemaphoreHandle_t semaphore;

void handleIncrement()
{
    currentEvent |= INCREMENT_EVENT;
    if (blinkInterval + intervalStep <= maxInterval)
    {
        blinkInterval += intervalStep;
    }
}

void handleDecrement()
{
    currentEvent |= DECREMENT_EVENT;
    if (blinkInterval - intervalStep >= minInterval)
    {
        blinkInterval -= intervalStep;
    }
}

void handleReset()
{
    currentEvent |= RESET_EVENT;

    intermittendLED.turnOff();
    greenLed.turnOn();

    blinkInterval = defaultInterval;
}

void handleToggle()
{
    currentEvent |= TOGGLE_EVENT;

    if (greenLed.getState())
    {
        greenLed.turnOff();
    }

    intermittendLED.turnOn();
}

void delayTask(void *params)
{
    static TickType_t taskDelay = pdMS_TO_TICKS(DELAY_TASK_DELAY);
    vTaskDelay(taskDelay);
    static unsigned long lastToggleTime;

    for (;;)
    {
        if (xSemaphoreTake(semaphore, portMAX_DELAY) == pdTRUE)
        {
            redButton.checkForClick();
            blueButton.checkForClick();

            if ((millis() - lastToggleTime >= blinkInterval) && !greenLed.getState())
            {
                intermittendLED.toggle();
                lastToggleTime = millis();
            }

            xSemaphoreGive(semaphore);
        }
        vTaskDelay(taskDelay);
    }
}

void resetTask(void *params)
{
    static TickType_t taskDelay = pdMS_TO_TICKS(RESET_TASK_DELAY);
    vTaskDelay(taskDelay);

    for (;;)
    {
        if (xSemaphoreTake(semaphore, portMAX_DELAY) == pdTRUE)
        {
            blackButton.checkForClick();
            xSemaphoreGive(semaphore);
        }
        vTaskDelay(taskDelay);
    }
}

void toggleTask(void *params)
{
    static TickType_t taskDelay = pdMS_TO_TICKS(TOGGLE_TASK_DELAY);
    vTaskDelay(taskDelay);

    for (;;)
    {
        if (xSemaphoreTake(semaphore, portMAX_DELAY) == pdTRUE)
        {
            greenButton.checkForClick();
            xSemaphoreGive(semaphore);
        }
        vTaskDelay(taskDelay);
    }
}

void idleTask(void *params)
{
    static TickType_t taskDelay = pdMS_TO_TICKS(IDLE_TASK_DELAY);
    for (;;)
    {
        if (xSemaphoreTake(semaphore, portMAX_DELAY) == pdTRUE)
        {
            eventManager.triggerEvent(currentEvent, blinkInterval);
            currentEvent = EVENT_NONE;
            xSemaphoreGive(semaphore);
        }
        vTaskDelay(taskDelay);
    }
}

void initializeComponents()
{
    redButton = Button(RED_BUTTON_PIN, handleIncrement);
    blueButton = Button(BLUE_BUTTON_PIN, handleDecrement);
    greenButton = Button(GREEN_BUTTON_PIN, handleToggle);
    blackButton = Button(BLACK_BUTTON_PIN, handleReset);

    greenLed = LED(GREEN_LED_PIN);
    intermittendLED = LED(INTERMITTENT_LED_PIN);

    greenLed.turnOn();
    intermittendLED.turnOff();

    semaphore = xSemaphoreCreateBinary();
    xSemaphoreGive(semaphore);
}
