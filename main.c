#include <xc.h>
#include "config.h"
#include "definitions.h"
#include "lcd.h"
#include "keypad.h"
#include "misc.h"

void setup()
{
    //0 == output
    //1 == input
    TRISBSET = 0xB00F; //0b1011 xxxx 0000 1111 ('x' = we did not use pin)
    TRISDSET = 0x7F00; //0b0111 1111 xxxx zzzz ('z' = pin does not exist)
    TRISESET = 0x00;   //0b0000 00xx
    
    LATESET = 0x00;
}

void testLCD() {
    lcd_init();
    lcd_printChar('H');
    lcd_printChar('i');
    delay(1000000);
    lcd_clear();
    
    lcd_print("Testing?", 8, 0, 0);
    delay(1000000);
    
    lcd_setDD(0x00 + 7);
    lcd_printChar('!');
}

int main (void)
{
    setup();
    testLCD();
}