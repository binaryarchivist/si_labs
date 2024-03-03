#ifndef LED_HPP
#define LED_HPP

class LED
{
private:
    int pin;

public:
    LED();
    LED(int pinNumber);

    void turnOn();
    void turnOff();
    bool getState();
    void toggle();
};

#endif
