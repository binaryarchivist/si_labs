#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "Arduino.h"

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
};

#endif
