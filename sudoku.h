#ifndef SUDOKU_H
#define SUDOKU_H

// Function declarations for Sudoku solver
bool isSafe(int board[9][9], int row, int col, int num);
bool solveBasic(int board[9][9]);
bool isValid(int board[9][9], int row, int col, int num);
bool isBoardFull(int board[9][9]);

#endif // SUDOKU_H
