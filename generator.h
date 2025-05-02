#pragma once

// Function declarations for generator
void generatePuzzle(int board[9][9]);
void fillDiagonal(int board[9][9]);
bool fillRemaining(int board[9][9], int row, int col);
void removeCells(int board[9][9], int numRemove);
bool isSafe(int board[9][9], int row, int col, int num);