#include "sudoku.h"

// Check if placing num in board[row][col] is valid
bool isSafe(int board[9][9], int row, int col, int num) {
    // Check row
    for (int x = 0; x < 9; x++) {
        if (board[row][x] == num) return false;
    }

    // Check column
    for (int x = 0; x < 9; x++) {
        if (board[x][col] == num) return false;
    }

    // Check 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) return false;
        }
    }

    return true;
}

// Check if the board is completely filled (no zeros)
bool isBoardFull(int board[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) return false;  // Empty cell found
        }
    }
    return true;  // No empty cell
}

// Backtracking function to solve the puzzle
bool solveBasic(int board[9][9]) {
    if (isBoardFull(board)) return true;  // Puzzle solved

    // Find the next empty cell
    int row, col;
    bool foundEmpty = false;
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                foundEmpty = true;
                break;
            }
        }
        if (foundEmpty) break;
    }

    // Try numbers from 1 to 9 in the empty cell
    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;  // Try placing num

            // Recursively solve the rest of the puzzle
            if (solveBasic(board)) return true;

            // Backtrack if the number didn't work
            board[row][col] = 0;
        }
    }

    return false;  // Trigger backtracking
}
