//basic keypad functions

//read input

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
				case 3: return NULL; //do nothing
			}
		case 1:
			switch (column) {
				case 0:	return '4';
				case 1: return '5';
				case 2: return '6';
				case 3: return NULL; //do nothing
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
				case 0:	return NULL; //do nothing
				case 1: return '0';
				case 2: return NULL; //do nothing
				case 3: return 'E'; //enter
			}
	}	
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