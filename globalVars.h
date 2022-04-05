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
int checkComplete(); // Function to check if the user has completed the entire board
