#ifndef LCD_H   /* Guard against multiple inclusion */
#define LCD_H

#define RS LATDbits.LATD1
#define RW LATDbits.LATD2
#define E LATDbits.LATD3
#define DB4 LATDbits.LATD4
#define DB5 LATDbits.LATD5
#define DB6 LATDbits.LATD6
#define DB7 LATDbits.LATD7

void lcd_print(char message[], int size, int row, int column);
void lcd_printChar(char character);
void lcd_init();
void lcd_shiftCursor(int RL);
void lcd_scroll(int RL);
int lcd_busy();
void lcd_clear();
void lcd_setDD(int address);

#endif