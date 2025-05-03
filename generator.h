#ifndef GENERATOR_H
#define GENERATOR_H

// Function declarations for generating a Sudoku puzzle
void generatePuzzle(int board[9][9]);
void shuffleBoard(int board[9][9]);
void initializeBoard(int board[9][9]);
void fillDiagonal(int board[9][9]);
void fillBox(int board[9][9], int row, int col);
void removeDigits(int board[9][9], int count);

#endif // GENERATOR_H
