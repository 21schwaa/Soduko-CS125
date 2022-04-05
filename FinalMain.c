#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include "check.c"

int rows = 9;
int columns = 9;
int gameScore = 0;
int board[9][9] = {{0, 5, 0,  0, 2, 9,  7, 0, 0},
                   {0, 0, 0,  4, 0, 0,  9, 0, 0},
                   {9, 1, 0,  0, 0, 7,  5, 0, 0},
                   
                   {7, 8, 0,  5, 0, 0,  4, 9, 0},
                   {0, 0, 9,  0, 0, 0,  8, 0, 5},
                   {0, 4, 5,  8, 9, 3,  0, 1, 7},
                   
                   {0, 0, 0,  9, 0, 0,  0, 5, 0},
                   {0, 0, 6,  0, 0, 8,  0, 0, 0},
                   {0, 0, 3,  0, 1, 0,  0, 4, 0}};

void printBoard(); // Function used to print the entire board and returns nothing
int checkNinth(int row, int col); // Function used to check what ninth the x and y coordinates are in and returns the ninth as an integer
bool checkNinthForNum(int ninth, int num); // Function used to check if the num is in the ninth and returns a bool
bool checkRowForNum(int row, int num); // Function used to check if the num is in the row and returns a bool
bool checkColForNum(int col, int num); // Function used to check if the num is in the column and returns a bool
bool checkCross(); // Function used to call all the functions needed to check if a number is valid and returns a bool
int userChange(); // Function used to let users input data into the board and calls other functions to check their input
int checkComplete();

int main() {
	FILE *f;
	f = fopen("LeaderBoard.txt", "w+");
	srand(time(NULL));
	clock_t begin = clock();
	int boardComplete = 0;
	char name[10];
	printf("Enter your name: ");
	scanf("%s", name);
	
	while(boardComplete == 0) {
		printBoard();
		userChange();
		if(checkComplete()) {
			boardComplete = 1;	
		}
	}
	printBoard();
	clock_t end = clock();
	double timeSpent = ((double)(end - begin)) / (double)CLOCKS_PER_SEC;
	printf("Completed in %f seconds", timeSpent);
	fprintf(f, "%s: %f seconds", name, timeSpent);
	return 0;
}

int checkComplete() {
	int numZeros = 0;
	for(int row = 0; row < rows; row ++) {
		for(int col = 0; col < columns; col ++) {
			if(board[row][col] == 0) {
				numZeros ++;
			}
		}
	}
	if(numZeros == 0) {
		return 1;	
	}
	return 0;
}

int userChange() {
	int temp;
	char userInputRow;
	int userNumber, userInputCol, place, entryNumber;
	place=0;
	printf("Where would you like to Input?\n");
	printf("Please enter a ROW:A-I:");
	scanf(" %c", &userInputRow);
	printf("Please enter a COL:1-9:");
	scanf("%d", &userInputCol);
	printf("What Number would you like to enter?");
	scanf("%d", &entryNumber);
	temp = board[place][userInputCol - 1];
	
	switch(userInputRow){
		case 'A':
			place=0;
			break;
		case 'B':
			place=1;
			break;
		case 'C':
			place=2;
			break;
		case 'D':
			place=3;
			break;
		case 'E':
			place=4;
			break;
		case 'F':
			place=5;
			break;
		case 'G':
			place=6;
			break;
		case 'H':
			place=7;
			break;
		case 'I':
			place=8;
			break;
		default:
			printf("Invalid Response");
	}
	
	if(board[place][userInputCol - 1] != 0) {
		board[place][userInputCol - 1] = 0;
	}
			
	if(checkCross(checkNinth(place, userInputCol-1), place, userInputCol - 1, entryNumber)) {
		printf("Entry correct, no numbers are overlapping\n");
		board[place][userInputCol-1] = entryNumber;
	}
	else {
		printf("Entry incorrect, numbers are overlapping\n");
		board[place][userInputCol - 1] = temp;
	}
}
	
bool checkCross(int ninth, int row, int col, int num) {
	//printf("checkCross\n");
	if(checkNinthForNum(ninth, num) && checkRowForNum(row, num) && checkColForNum(col, num)) {
		//printf(" checkNinthForNum %d\n", checkNinthForNum(ninth, num));
		//printf(" checkRowForNum   %d\n", checkRowForNum(row, num));
		//printf(" checkColForNum   %d\n", checkColForNum(col, num));
		return true;
	}
	return false;
}

bool checkNinthForNum(int ninth, int num) {
	//printf("checkNinthForNum\n");
	int startRow, endRow, startCol, endCol;
	switch(ninth) { // Assigns the ninth to its cordinates on the board
		case 1 : 
			startRow = 0;
			endRow = 2;
			startCol = 0;
			endCol = 2;
			for(startRow = 0; startRow <= endRow; startRow ++) {
				for(startCol = 0; startCol <= endCol; startCol ++){
					if(num == board[startRow][startCol]) {
						return false;
					}
				}
			}
			break;
		case 2 : 
			startRow = 3;
			endRow = 5;
			startCol = 0;
			endCol = 2;
			for(startRow = 3; startRow <= endRow; startRow ++) {
				for(startCol = 0; startCol <= endCol; startCol ++){
					if(num == board[startRow][startCol]) {
						return false;
					}
				}
			}
			break;
		case 3 :
			startRow = 6;
			endRow = 8;
			startCol = 0;
			endCol = 2;
			for(startRow = 6; startRow <= endRow; startRow ++) {
				for(startCol = 0; startCol <= endCol; startCol ++){
					if(num == board[startRow][startCol]) {
						return false;
					}
				}
			}
			break;
		case 4 :
			startRow = 0;
			endRow = 2;
			startCol = 3;
			endCol = 5;
			for(startRow = 0; startRow <= endRow; startRow ++) {
				for(startCol = 2; startCol <= endCol; startCol ++){
					if(num == board[startRow][startCol]) {
						return false;
					}
				}
			}
			break;
		case 5 :
			startRow = 3;
			endRow = 5;
			startCol = 3;
			endCol = 5;
			for(startRow = 3; startRow <= endRow; startRow ++) {
				for(startCol = 3; startCol <= endCol; startCol ++){
					if(num == board[startRow][startCol]) {
						return false;
					}
				}
			}
			break;
		case 6 :
			startRow = 6;
			endRow = 8;
			startCol = 3;
			endCol = 5;
			for(startRow = 6; startRow <= endRow; startRow ++) {
				for(startCol = 3; startCol <= endCol; startCol ++){
					if(num == board[startRow][startCol]) {
						return false;
					}
				}
			}
			break;
		case 7 :
			startRow = 0;
			endRow = 2;
			startCol = 6;
			endCol = 8;
			for(startRow = 0; startRow <= endRow; startRow ++) {
				for(startCol = 6; startCol <= endCol; startCol ++){
					if(num == board[startRow][startCol]) {
						return false;
					}
				}
			}
			break;
		case 8 :
			startRow = 3;
			endRow = 5;
			startCol = 6;
			endCol = 8;
			for(startRow = 3; startRow <= endRow; startRow ++) {
				for(startCol = 6; startCol <= endCol; startCol ++){
					if(num == board[startRow][startCol]) {
						return false;
					}
				}
			}
			break;
		case 9 :
			startRow = 6;
			endRow = 8;
			startCol = 6;
			endCol = 8;
			for(startRow = 6; startRow <= endRow; startRow ++) {
				for(startCol = 6; startCol <= endCol; startCol ++){
					if(num == board[startRow][startCol]) {
						return false;
					}
				}
			}
			break;
	}

	
	return true;
}

bool checkRowForNum(int row, int num) {
	//printf("checkRowForNum\n");
	for(int i = 0; i <= 8; i ++) {
		if(board[row][i] == num) {
			return false;
		}
	}
	return true;
}

bool checkColForNum(int col, int num) {
	//printf("checkColForNum\n");
	for(int i = 0; i <= 8; i ++) {
		if(board[i][col] == num) {
			return false;
		}
	}
	return true;
}

void printBoard() {
	int x = 0;
	int y = 0;
	int i = 0;
  
	printf(" ");
	for(i = 0; i < rows; i ++) {
        	printf("  %d ", i + 1);
	}
	for(x = 0 ; x < rows ; x++) {
        	printf("\n -------------------------------------\n");
        	printf("%c", x + 65);
        	for(y = 0 ; y < columns ; y++){
        		if(board[x][y] == 0) {
        			printf("|   ");
        		}
        		else {
        			printf("| %d ", board[x][y]);
        		}
        	}
        printf("|");
	}
	printf("\n -------------------------------------\n");	
}
