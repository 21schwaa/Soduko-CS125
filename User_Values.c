#include <stdio.h>

int main(){

char userInputRow;
int userNumber, userInputCol, place;
place=0;
printf("Where would you like to Input?\n");
printf("Please enter a ROW:A-I:");
scanf("%c", &userInputRow);
printf("Please enter a COL:1-9:");
scnaf("%d", &userInputCol);
printf("What Number would you like to enter?");
scanf("%d", entryNumber);

switch(UserInputRow){
	case 'A':
		place=1;
		break;
	case 'B':
		place=2;
		break;
	case 'C':
		place=3;
		break;
	case 'D':
		place=4;
		break;
	case 'F':
		place=5;
		break;
	case 'E':
		place=6;
		break;
	case 'G':
		place=7;
		break;
	case 'H':
		place=8;
		break;
	case 'I':
		place=9;
		break;
	default:
		printf("Invalid Response");
}
		
  

if (userInputCol == 1){
	board[place][1]=entryNumber;
}
if (userInputCol == 2){
	board[place][2]=entryNumber;
}
if (userInputCol == 3){
	board[place][3]=entryNumber;
}
if (userInputCol == 4){
	board[place][4]=entryNumber;
}
if (userInputCol == 5){
	board[place][5]=entryNumber;
}
	
if (userInputCol == 6){
	board[place][6]=entryNumber;
}
if (userInputCol == 7){
	board[place][7]=entryNumber;
}
if (userInputCol == 8){
	board[place][8]=entryNumber;
}
if (userInputCol == 9){
	board[place][9]=entryNumber;
}
	

	
	
	
}
