#ifndef KEYPAD_H   /* Guard against multiple inclusion */
#define KEYPAD_H

char kp_getSymbol(int row, int column);
int kp_modifyTotal(int total, char input);
char kp_scanForInput();
int kp_getBatchSize(char message[], int size);

#endif
