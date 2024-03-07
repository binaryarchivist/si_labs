#include "Logger.hpp"
#include <LiquidCrystal_I2C.h>

Logger *Logger::instance = nullptr;

const int LCD_ADDR = 0x27;
const int LCD_COLUMNS = 20;
const int LCD_ROWS = 4;

LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLUMNS, LCD_ROWS);

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
    // if (c == '\n') {
    //     lcd.clear();
    //     lcd.setCursor(0, 0);
    //     return 1;
    // }
    lcd.print(c);
    return 1;
}

int Logger::getChar(FILE *f)
{
    while (!Serial.available());
    return Serial.read();
}

void Logger::clearScreen()
{
    lcd.clear();
    lcd.setCursor(0, 0);
}
