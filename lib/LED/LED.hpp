#ifndef LED_HPP
#define LED_HPP

class LED
{
private:
    int pin;

public:
    bool state;

    LED();
    LED(int pinNumber);
    void turn(bool mode = true);
};

#endif
