#include <xc.h>
#include "config.h"

#include "lcd.h"
#include "keypad.h"
#include "misc.h"
 

#define DEBUG LATEbits.LATE5

void setup()
{
    //0 == output
    //1 == input
    TRISBSET = 0xB00F; //0b1011 xxxx 0000 1111 ('x' = we did not use pin)
    TRISDSET = 0x7F00; //0b0111 1111 xxxx zzzz ('z' = pin does not exist)
    TRISESET = 0x00;   //0b0000 00xx
    
    LATESET = 0x00;
}

int main (void) {
    setup();
    LATEbits.LATE5 = 1;
    misc_blinkDebug(40);
}