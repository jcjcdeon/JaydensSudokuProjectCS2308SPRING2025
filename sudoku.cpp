#include "sudoku.h"
#include <iostream>

/**
 * A simple Sudoku solver placeholder.
 * Returns true if solving is successful.
 */
bool solveBasic(int board[9][9]) {
    // Placeholder: implement your actual solving algorithm here
    return true;
}

/**
 * Prints the Sudoku board to the console.
 */
void printBoard(const int board[9][9]) {
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            std::cout << board[r][c] << " ";
        }
        std::cout << "\n";
    }
}
