#include "Logger.hpp"

Logger *Logger::instance = nullptr;

Logger::Logger(unsigned long baudRate)
{
    Serial.begin(baudRate);
    while (!Serial);

    stdin = stdout = fdevopen(&Logger::putCharWrapper, &Logger::getCharWrapper);
}

Logger *Logger::getInstance(unsigned long baudRate)
{
    if (instance == nullptr)
    {
        instance = new Logger(baudRate);
    }
    return instance;
}

int Logger::putCharWrapper(char c, FILE *f)
{
    return instance->putChar(c, f);
}

int Logger::getCharWrapper(FILE *f)
{
    return instance->getChar(f);
}

int Logger::putChar(char c, FILE *f)
{
    return Serial.write(c);
}

int Logger::getChar(FILE *f)
{
    while (!Serial.available());
    return Serial.read();
}
