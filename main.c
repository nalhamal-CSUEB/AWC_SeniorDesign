#include <xc.h>
#include "config.h"

void setup()
{
    TRISEbits.TRISE5 = 0; //pin 1 - debug led RE5
}

volatile void ledBlink()
{
    for (int i = 0; i < 1000000; i++)
    {
        int j = 0;
        j += 1;
        _nop();      
    }
}

int main (void)
{
    setup();
    
    while (1)
    {
        
        LATEbits.LATE5 = 0;
        
        ledBlink();
        
        LATEbits.LATE5 = 1;
        
        ledBlink();
    }
    
}