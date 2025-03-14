#include "adc.h"

#include <xc.h>
/*
 
void configANPins();
void configIntoMux();
void setOutputFormat();
void setSampleClockSource();
void setVoltageRefs();
void selectScanMode();
void setConvPerInterrupt();
void setBufferFillMode();
void setMuxToADCConnection();
void setADCClockSource();
void setSampleTime();
void setADCClockPrescaler();

void setupADC();

void turnOnADC();
void turnOffADC();
 
 
 */

void configANPins()
{
    //set the digital pins first
    //setting AD1PCFG<n> = 1 will make it a digital input
    
    //CLR,SET, and INV registers only modify values with '1', values with '0' are unmodified
    
    AD1PCFGSET = 0x0000FFF3; //all pins besides AN2 and AN3 are set to digital
    AD1PCFGCLR = 0x0000000C; //make AN2 and AN3 analog input
    
    //Port B is where AN2 and AN3 are located
    //Set their TRIS bits to 1 to read as input
    
    TRISBSET = 0x0000000C;
    
    
    
}
