#include "generator.h"
#include <random>
#include <algorithm>
#include <iostream>

// Function to initialize a board to all zeros
void initializeBoard(int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board[i][j] = 0;
        }
    }
}

// Function to fill the diagonal 3x3 subgrids
void fillDiagonal(int board[9][9]) {
    for (int i = 0; i < 9; i += 3) {
        shuffleBoard(board);
        fillBox(board, i, i);
    }
}

// Function to fill a 3x3 box with valid numbers
void fillBox(int board[9][9], int row, int col) {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::shuffle(nums.begin(), nums.end(), std::default_random_engine{});
    int k = 0;
    for (int i = row; i < row + 3; ++i) {
        for (int j = col; j < col + 3; ++j) {
            board[i][j] = nums[k++];
        }
    }
}

// Function to shuffle the board to create randomness
void shuffleBoard(int board[9][9]) {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::shuffle(nums.begin(), nums.end(), std::default_random_engine{});
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board[i][j] = nums[j];
        }
    }
}

// Function to remove digits from the board to create a puzzle
void removeDigits(int board[9][9], int count) {
    while (count != 0) {
        int row = rand() % 9;
        int col = rand() % 9;
        if (board[row][col] != 0) {
            board[row][col] = 0;
            count--;
        }
    }
}

// Generate a solvable puzzle
void generatePuzzle(int board[9][9]) {
    initializeBoard(board);
    fillDiagonal(board);
    removeDigits(board, 40);  // Randomly remove 40 digits
}
