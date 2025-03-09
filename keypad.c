//basic keypad functions

#include "lcd.h"
#include <xc.h>

//#define B8 Lat

char kp_getSymbol(int row, int column) { 

	//assuming row and column will be between 0 - 3
	//scaling for final matrix may be different, double check!
    
    //converts a row and column into the corresponding character on the keypad
    
    //e.g. hitting the top left button (row 0 column 0 for example)
    //should return the character '1'

	switch (row) {
		case 0:
			switch (column) {
				case 0:	return '1';
				case 1: return '2';
				case 2: return '3';
				case 3: return 'N'; //do nothing
			}
		case 1:
			switch (column) {
				case 0:	return '4';
				case 1: return '5';
				case 2: return '6';
				case 3: return 'N'; //do nothing
			}
		case 2:
			switch (column) {
				case 0:	return '7';
				case 1: return '8';
				case 2: return '9';
				case 3: return 'D'; //delete
			}
		case 3:
			switch (column) {
				case 0:	return 'N'; //do nothing
				case 1: return '0';
				case 2: return 'N'; //do nothing
				case 3: return 'E'; //enter
			}
	}	
    return 'N';
}

int kp_modifyTotal(int total, char input) {

    //takes parameter total and updates it depending on the inputted character
    //inputted character is scanned by keypad
    
    //because it reads as a character, there needs to be a function to track
    //the total length/amount after each button press
    
	switch (input) {
		case '0':										//if input is a numeric digit
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': return (total * 10) + (input - 48); 	//shift current digits to left, 
														//convert input from ascii to digit,
														//then append digit to total with addition

		case 'D': return (total / 10);					//if digit is deleted, move all digits right,
														//truncating off removed digit

		default: return total;							//do nothing in case of null or enter
	}
}

char kp_scanForInput() {
    
    //loop across every keypad input port to test for connection
    //connection established when button is pressed
    //row and column of button press is determined as we loop
    //the corresponding character is returned from getSymbol()
    
	for (int i = 8; i < 12; i++) { 				//loop across output ports

		/*latBbits[i] = 1; 					//turn each output port on one by one and test for connection
											//keypad drive pins start at RB8
											
		for (int j = 12; j < 16; j++) { 		//loop across receiving pins

			if (readBbits[j] == 1) { 		//keypad-in bits start at RB12
											//if connection is found 
				return getSymbol(i, j); 	//find corresponding symbol for button input
			}	
		}
		latBbits[i + 8] = 0; */				//turn on current output port and check next
	}

	return 'N'; //if nothing is found
}

int kp_getBatchSize(char message[], int size) { 

	//will be inside main 
	//it's purpose is to return the value we are asking for in "message"
    
    //scans for keypad input until 'E' or "enter" is pressed
    //if button pressed is not enter, tracks the character user touched
    //outputs this character on the LCD screen for user convenience
    //numerical total is kept track via 
    //characters can be deleted, and changes are t
    //tracks the total by converting

	lcd_clear(); 						//clear after booting
	lcd_print(message, size, 1, 1);			//prompt user to input
	lcd_setDD(0x40);					//place cursor on second row

	int position = 1;	//for cursor position in LCD row
	char input = 'N';	//stores user input
	int total = 0;		//stores total value
	

	do {
		input = kp_scanForInput(); 				//check for button input
												//returns null if no buttons pressed
												
		if (input == 'N') { 					//if no valid buttons pressed
			continue;							//do nothing and rescan		
		}

		total = kp_modifyTotal(total, input);		//returns total after appending/deleting new input
		
		
		if (input == 'D' && position > 1) { 	//if we are deleting,
			position = position - 1; 			//go to previous character
            lcd_setDD(0x40 + position);         //place cursor over character to delete
            lcd_printChar(' ');                 //print empty character (delete character)
            lcd_setDD(0x40 + position);         //move cursor back over empty space
			
		} else if (input != 'E') {              //if not deleted and not entering,
            lcd_printChar(input);               //print numerical character
        }

		//__delay_ms(500); //make our own delay function

	} while (input != 'E');
	
	return total; //return entered amount to main
}