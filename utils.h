#ifndef UTILS_H
#define UTILS_H

/**
 * Deallocates memory used for the Sudoku grid.
 *
 * @param board The 9x9 Sudoku grid to deallocate.
 */
void deallocateBoard(int board[9][9]);

/**
 * Initializes a new 9x9 Sudoku board with all elements set to zero.
 *
 * @param board The 9x9 Sudoku grid to initialize.
 */
void initializeBoard(int board[9][9]);

#endif // UTILS_H
