#include "generator.h"
#include <algorithm>
#include <random>
#include <ctime>
#include "sudoku.h"  // now includes solveBoard declaration

void generateBoard(int board[9][9]) {
    clearBoard(board);
    fillDiagonalBoxes(board);
    solveBoard(board); // fill a complete valid board
    removeDigits(board); // create puzzle
}

void clearBoard(int board[9][9]) {
    for (int i = 0; i < 9; ++i)
        std::fill(board[i], board[i] + 9, 0);
}

void fillDiagonalBoxes(int board[9][9]) {
    for (int i = 0; i < 9; i += 3)
        fillBox(board, i, i);
}

void fillBox(int board[9][9], int row, int col) {
    std::vector<int> nums{1,2,3,4,5,6,7,8,9};
    std::shuffle(nums.begin(), nums.end(), std::mt19937(std::random_device()()));
    int k = 0;
    for (int i = row; i < row + 3; ++i)
        for (int j = col; j < col + 3; ++j)
            board[i][j] = nums[k++];
}

void removeDigits(int board[9][9]) {
    int count = 40;
    while (count--) {
        int i = rand() % 9, j = rand() % 9;
        board[i][j] = 0;
    }
}
