#include <iostream>
using namespace std;

const int SIZE = 9;

// Function to print the Sudoku grid
void printGrid(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Function to check if a number is already present in a row
bool isNumberInRow(int grid[SIZE][SIZE], int row, int num) {
    for (int col = 0; col < SIZE; col++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

// Function to check if a number is already present in a column
bool isNumberInColumn(int grid[SIZE][SIZE], int col, int num) {
    for (int row = 0; row < SIZE; row++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

// Function to check if a number is already present in a 3x3 box
bool isNumberInBox(int grid[SIZE][SIZE], int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + boxStartRow][col + boxStartCol] == num) {
                return true;
            }
        }
    }
    return false;
}

// Function to check if it's safe to place a number in a given cell
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
    return !isNumberInRow(grid, row, num) &&
           !isNumberInColumn(grid, col, num) &&
           !isNumberInBox(grid, row - row % 3, col - col % 3, num);
}

// Function to find the next empty cell in the grid
bool findEmptyCell(int grid[SIZE][SIZE], int& row, int& col) {
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(int grid[SIZE][SIZE]) {
    int row, col;

    if (!findEmptyCell(grid, row, col)) {
        return true; // All cells filled, solution found
    }

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid)) {
                return true; // Solution found
            }

            grid[row][col] = 0; // Backtrack and try a different number
        }
    }

    return false; // No solution found
}

int main() {
    int grid[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Sudoku grid before solving:" << endl;
    printGrid(grid);

    if (solveSudoku(grid)) {
        cout << "Sudoku grid solved successfully:" << endl;
        printGrid(grid);
    }
    else {
        cout << "No solution exists for the given Sudoku grid." << endl;
    }

    return 0;
}

