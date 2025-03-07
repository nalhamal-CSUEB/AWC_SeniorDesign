//basic keypad functions

//read input

char getSymbol(int row, int column) { 

	//assuming row and column will be between 0 - 3
	//scaling for final matrix may be different, double check!

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