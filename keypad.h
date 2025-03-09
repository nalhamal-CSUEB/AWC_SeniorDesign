#ifndef KEYPAD_H   /* Guard against multiple inclusion */
#define KEYPAD_H

char kp_getSymbol(int row, int column);
char kp_scanForInput();

#endif
