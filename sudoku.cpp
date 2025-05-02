#include "sudoku.h"

// Helper: Check if placing num at board[row][col] is valid
bool isValid(int board[9][9], int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num)
            return false;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[startRow + i][startCol + j] == num)
                return false;

    return true;
}

// Basic recursive backtracking Sudoku solver
bool solveBasic(int board[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveBasic(board))
                            return true;
                        board[row][col] = 0;
                    }
                }
                return false; // Trigger backtracking
            }
        }
    }
    return true; // Solved
}

// Placeholder for efficient solver (can reuse for now)
bool solveEfficient(int board[9][9]) {
    return solveBasic(board);
}

// Validate current board state
bool validatePuzzle(int board[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            int num = board[row][col];
            if (num != 0) {
                board[row][col] = 0; // Temporarily clear
                if (!isValid(board, row, col, num)) {
                    board[row][col] = num; // Restore before returning
                    return false;
                }
                board[row][col] = num;
            }
        }
    }
    return true;
}
