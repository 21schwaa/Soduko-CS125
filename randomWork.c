#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int rows = 9;
int columns = 9;
int point[2];
int board[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0}};


void printBoard(); // Function used to print the entire board and returns nothing
void createRandBoard();	// Function used to create the intial fully solved board and returns nothing
int checkNinth(int row, int col); // Function used to check what ninth the x and y coordinates are in and returns the ninth as an integer
int randPoint(); // Function assigns a random point on the board
bool checkNinthForNum(int ninth, int num); // Function used to check if the num is in the ninth and returns a bool
bool checkRowForNum(int row, int num); // Function used to check if the num is in the row and returns a bool
bool checkColForNum(int col, int num); // Function used to check if the num is in the column and returns a bool
bool checkCross(); // Function used to call all the functions needed to check if a number is valid and returns a bool

int main() {
	srand(time(NULL));
	createRandBoard();
	printf("Passed createRandBoard\n");
	printBoard();
	return 0;
}

void createRandBoard() {
	int row = point[0];
	int col = point[1];
	int numOnes = 0;
	while(numOnes != 9) {
		randPoint();
		row = point[0];
		col = point[1];
		printf("Rand Point: %d,%d\n", row, col);
		if(checkCross(checkNinth(row, col), row, col, 1)) {
			board[row][col] = 1;
			numOnes ++;
		}
		printf("While Loop\n");
	}
}

bool checkCross(int ninth, int row, int col, int num) {
	printf("checkCross\n");
	if(checkNinthForNum(ninth, num) && checkRowForNum(row, num) && checkColForNum(col, num)) {
		printf(" checkNinthForNum %d\n", checkNinthForNum(ninth, num));
		printf(" checkRowForNum   %d\n", checkRowForNum(row, num));
		printf(" checkColForNum   %d\n", checkColForNum(col, num));
		return true;
	}
	return false;
}

bool checkNinthForNum(int ninth, int num) {
	printf("checkNinthForNum\n");
	int startRow, endRow, startCol, endCol;
	switch(ninth) { // Assigns the ninth to its cordinates on the board
		case 1 : 
			startRow = 0;
			endRow = 2;
			startCol = 0;
			endCol = 2;
			break;
		case 2 : 
			startRow = 3;
			endRow = 5;
			startCol = 0;
			endCol = 2;
			break;
		case 3 :
			startRow = 6;
			endRow = 8;
			startCol = 0;
			endCol = 2;
			break;
		case 4 :
			startRow = 0;
			endRow = 2;
			startCol = 3;
			endCol = 5;
			break;
		case 5 :
			startRow = 3;
			endRow = 5;
			startCol = 3;
			endCol = 5;
			break;
		case 6 :
			startRow = 6;
			endRow = 8;
			startCol = 3;
			endCol = 5;
			break;
		case 7 :
			startRow = 0;
			endRow = 2;
			startCol = 6;
			endCol = 8;
			break;
		case 8 :
			startRow = 3;
			endRow = 5;
			startCol = 6;
			endCol = 8;
			break;
		case 9 :
			startRow = 6;
			endRow = 8;
			startCol = 6;
			endCol = 8;
			for(startRow = 6; startRow <= endRow; startRow ++) {
				for(startCol; startCol <= endCol; startCol ++){
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
	printf("checkRowForNum\n");
	for(int i = 0; i <= 8; i ++) {
		if(board[row][i] == num) {
			return false;
		}
	}
	return true;
}

bool checkColForNum(int col, int num) {
	printf("checkColForNum\n");
	for(int i = 0; i <= 8; i ++) {
		if(board[i][col] == num) {
			return false;
		}
	}
	return true;
}

int checkNinth(int row, int col) {
	printf("checkNinth\n");
	if((row >= 0 && row <=2) && (col >= 0 && col <= 2)) {
		//printf("1\n");
		return 1;
	}
	else if((row >= 3 && row <=5) && (col >= 0 && col <= 2)) {
		//printf("2\n");
		return 2;
	}
	else if((row >= 6 && row <=8) && (col >= 0 && col <= 2)) {
		//printf("3\n");
		return 3;
	}
	else if((row >= 0 && row <=2) && (col >= 3 && col <= 5)) {
		//printf("4\n");
		return 4;
	}
	else if((row >= 3 && row <=5) && (col >= 3 && col <= 5)) {
		//printf("5\n");
		return 5;
	}
	else if((row >= 6 && row <=8) && (col >= 3 && col <= 5)) {
		//printf("6\n");
		return 6;
	}
	else if((row >= 0 && row <=2) && (col >= 6 && col <= 8)) {
		//printf("7\n");
		return 7;
	}
	else if((row >= 3 && row <=5) && (col >= 6 && col <= 8)) {
		//printf("8\n");
		return 8;
	}
	else if((row >= 6 && row <=8) && (col >= 6 && col <= 8)) {
		//printf("9\n");
		return 9;
	}
	return 0;
}

int randPoint() {
	printf("randPoint\n");
	point[0] = rand() % 9;
	point[1] = rand() % 9;
}

void printBoard() {
	int x = 0;
	int y = 0;
	int i = 0;
  
	printf(" ");
	for(i = 0; i < rows; i ++) {
        	printf("  %c ", i + 65);
	}
	for(x = 0 ; x < rows ; x++) {
        	printf("\n -------------------------------------\n");
        	printf("%d", x + 1);
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
