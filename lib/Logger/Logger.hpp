#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "Arduino.h"

#include <LiquidCrystal_I2C.h>

// Constants
extern const int LCD_ADDR;
extern const int LCD_COLUMNS;
extern const int LCD_ROWS;

extern LiquidCrystal_I2C lcd;

class Logger
{
private:
    static Logger* instance;

    Logger(unsigned long baudRate = 9600);

public:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger* getInstance(unsigned long baudRate = 9600);

    static int putCharWrapper(char c, FILE *f);
    static int getCharWrapper(FILE *f);

    int putChar(char c, FILE *f);
    int getChar(FILE *f);
    void clearScreen();
};

#endif
