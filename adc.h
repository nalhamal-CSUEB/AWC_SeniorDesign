#ifndef ADC_H
#define ADC_H

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
void setAlternateMode();

void setupADC();

void turnOnADC();
void turnOffADC();





#endif