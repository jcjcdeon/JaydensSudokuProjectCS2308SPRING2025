#ifndef GENERATOR_H
#define GENERATOR_H

/**
 * Initializes a 9x9 Sudoku board with zeros.
 * @param board The 9x9 Sudoku grid to initialize
 */
void initializeBoard(int board[9][9]);

/**
 * Generates a fully solved, valid Sudoku board.
 * @param board The 9x9 grid to fill with a complete solution
 */
void generateCompleteBoard(int board[9][9]);

/**
 * Generates a Sudoku puzzle with a specified number of clues.
 * @param board The 9x9 grid to fill with a puzzle
 * @param clues The number of filled cells to retain (difficulty)
 */
void generatePuzzle(int board[9][9], int clues);

/**
 * Randomly shuffles rows and columns within 3x3 blocks.
 * Used to obscure the pattern of a solved board.
 * @param board The 9x9 grid to shuffle
 */
void shuffleBoard(int board[9][9]);

#endif // GENERATOR_H
