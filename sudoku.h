#ifndef SUDOKU_H
#define SUDOKU_H

// Function to solve Sudoku using basic backtracking
bool solveBasic(int board[9][9]);

// Function to solve Sudoku using a more optimized method (if implemented)
bool solveEfficient(int board[9][9]);

// Check if a number can be placed at (row, col)
bool isValid(int board[9][9], int row, int col, int num);

// Validate if a completed board is a valid Sudoku solution
bool isValidBoard(int board[9][9]);

#endif // SUDOKU_H
