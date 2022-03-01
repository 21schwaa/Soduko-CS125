#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int rows = 9;
int columns = 9;
int row[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int col[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int ninth[3][3] = {{0, 0, 0},
		   {0, 0, 0},
		   {0, 0, 0}};
int board[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0}};


void printBoard();
void createRandBoard();
int checkNinth();
void randPoint(int* row, int* col);
void copyNinth(int numNinth);

void main() {
	srand(time(NULL));
	createRandBoard();
	printBoard();
}

void createRandBoard() {
	int fillSquares = 20;
	int randRow, randCol;
	int numNinth;
	randPoint(&randRow, &randCol);
	board[randCol][randRow] = 1;
	numNinth = checkNinth(randRow, randCol);
	copyNinth(numNinth);
}

int checkNinth(int row, int col) {
	if((row >= 0 && row <=2) && (col >= 0 && col <= 2)) {
		printf("1\n");
		return 1;
	}
	else if((row >= 3 && row <=5) && (col >= 0 && col <= 2)) {
		printf("2\n");
		return 2;
	}
	else if((row >= 6 && row <=8) && (col >= 0 && col <= 2)) {
		printf("3\n");
		return 3;
	}
	else if((row >= 0 && row <=2) && (col >= 3 && col <= 5)) {
		printf("4\n");
		return 4;
	}
	else if((row >= 3 && row <=5) && (col >= 3 && col <= 5)) {
		printf("5\n");
		return 5;
	}
	else if((row >= 6 && row <=8) && (col >= 3 && col <= 5)) {
		printf("6\n");
		return 6;
	}
	else if((row >= 0 && row <=2) && (col >= 6 && col <= 8)) {
		printf("7\n");
		return 7;
	}
	else if((row >= 3 && row <=5) && (col >= 6 && col <= 8)) {
		printf("8\n");
		return 8;
	}
	else if((row >= 6 && row <=8) && (col >= 6 && col <= 8)) {
		printf("9\n");
		return 9;
	}
}

void copyNinth(int numNinth) {
	
}

void randPoint(int* row, int* col) {
	*row = rand() % 9;
	*col = rand() % 9;
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
        	printf("| %d ", board[x][y]);
        	}
        printf("|");
	}
	printf("\n -------------------------------------\n");	
}
