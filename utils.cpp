#include "utils.h"
#include <iostream>

/**
 * Deallocates memory used for the Sudoku grid.
 *
 * @param board The 9x9 Sudoku grid to deallocate.
 */
void deallocateBoard(int board[9][9]) {
    // In C++, deallocation is not needed for statically allocated arrays
    // This function is a placeholder to maintain uniformity
    std::cout << "Deallocating board..." << std::endl;
}

/**
 * Initializes a new 9x9 Sudoku board with all elements set to zero.
 *
 * @param board The 9x9 Sudoku grid to initialize.
 */
void initializeBoard(int board[9][9]) {
    // Set all cells in the board to zero
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board[i][j] = 0;
        }
    }
}
