#include <Arduino.h>
#include "lcd.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

void lcdSetup()
{
    lcd.init(); // initialize the lcd

    // Print a message to the LCD.
    lcd.backlight();
}

bool PedCount()
{
    for (int i = 10; i > 0; i--)
    {

        lcd.clear();

        lcd.setCursor(1, 0);
        lcd.print("CROSS NOW!:");
        lcd.setCursor(2, 1);
        lcd.print(i);
        lcd.print("s left");
        delay(1150);
    }
    lcd.clear();
    return true;
}
