#include "generator.h"
#include <cstdlib>
#include <ctime>
#include <cstring>

// Helper: Check if placing num at board[row][col] is safe
bool isSafe(int board[9][9], int row, int col, int num) {
    for (int x = 0; x < 9; x++) {
        if (board[row][x] == num || board[x][col] == num)
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

// Fill a 3x3 box starting at (row, col) with random numbers
void fillBox(int board[9][9], int rowStart, int colStart) {
    int num;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            do {
                num = rand() % 9 + 1;
            } while (!isSafe(board, rowStart + i, colStart + j, num));
            board[rowStart + i][colStart + j] = num;
        }
    }
}

// Fill all diagonal 3x3 boxes
void fillDiagonal(int board[9][9]) {
    for (int i = 0; i < 9; i += 3)
        fillBox(board, i, i);
}

// Recursively fill remaining cells
bool fillRemaining(int board[9][9], int row, int col) {
    if (col >= 9 && row < 8) {
        row++;
        col = 0;
    }
    if (row >= 9 && col >= 9)
        return true;

    if (row < 3 || (row < 6 && col < 3) || (row >= 6 && col >= 6))
        col = 3;

    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (fillRemaining(board, row, col + 1))
                return true;
            board[row][col] = 0;
        }
    }
    return false;
}

// Remove K cells from the board to create a puzzle
void removeCells(int board[9][9], int numRemove) {
    while (numRemove > 0) {
        int i = rand() % 9;
        int j = rand() % 9;
        if (board[i][j] != 0) {
            board[i][j] = 0;
            numRemove--;
        }
    }
}

// Main puzzle generator
void generatePuzzle(int board[9][9]) {
    memset(board, 0, sizeof(int) * 81);
    srand(time(0));
    fillDiagonal(board);
    fillRemaining(board, 0, 3);
    removeCells(board, 40); // Remove 40 cells (adjust for difficulty)
}
