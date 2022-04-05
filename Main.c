#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include "globalVars.h"

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

int checkNinth(int row, int col) {
	//printf("checkNinth\n");
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

int userChange() {
	int temp, userCorrect;
	char userInputRow;
	int userNumber, userInputCol, place, entryNumber;
	place=0;
	userCorrect = 0;
	while(!userCorrect) {
		printf("Where would you like to Input?\n");
		printf("Please enter a ROW:A-I:");
		scanf(" %c", &userInputRow);
		if(userInputRow == 'A' | userInputRow == 'B' | userInputRow == 'C' | userInputRow == 'D' 
		| userInputRow == 'E' | userInputRow == 'F' | userInputRow == 'G' | userInputRow == 'H' 
		| userInputRow == 'I'){
			userCorrect = 1;
		} 
		else {
			printf("Entry incorrect\n");
		}
	}
	userCorrect = 0;
	
	while(!userCorrect) {
		printf("Please enter a COL:1-9:");
		scanf("%d", &userInputCol);
		if(userInputCol >= 1 && userInputCol <= 9){
			userCorrect = 1;
		} 
		else {
			printf("Entry incorrect\n");
		}
	}
	userCorrect = 0;
	
	while(!userCorrect) {
		printf("What Number would you like to enter?");
		scanf("%d", &entryNumber);
		if(entryNumber >= 1 && entryNumber <= 9){
			userCorrect = 1;
		} 
		else {
			printf("Entry incorrect\n");
		}
	}
	userCorrect = 0;
	
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
