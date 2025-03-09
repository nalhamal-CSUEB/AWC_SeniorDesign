#ifndef MISC_H   /* Guard against multiple inclusion */
#define MISC_H

volatile void delay(int num);
void debug_blink(int numTimes);
int modifyTotal(int total, char input);
int getBatchSize(char message[], int size);
void testKeypad();
void testLCD();

#endif