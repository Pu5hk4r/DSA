#include<iostream>
using namespace std;

bool isSafe(int mat[][9], int i, int j, int no) {
    // Check for row and col
    for (int k = 0; k < 9; k++) {
        if (mat[k][j] == no || mat[i][k] == no) {
            return false;
        }
    }
    // Check for subgrid
    int sx = (i / 3) * 3;
    int sy = (j / 3) * 3;
    for (int x = sx; x < sx + 3; x++) {
        for (int y = sy; y < sy + 3; y++) {
            if (mat[x][y] == no) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int mat[][9], int i, int j, int n) {
    // Base case: If we have reached the end of the board
    if (i == n) {
        // Print the solution
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }

    // Move to the next cell
    if (j == n) {
        return solveSudoku(mat, i + 1, 0, n);
    }

    // Skip the prefilled cell
    if (mat[i][j] != 0) {
        return solveSudoku(mat, i, j + 1, n);
    }

    // Try all possibilities for the current cell
    for (int no = 1; no <= n; no++) {
        if (isSafe(mat, i, j, no)) {
            mat[i][j] = no;
            if (solveSudoku(mat, i, j + 1, n)) {
                return true;
            }
            // Backtrack if not successful
            mat[i][j] = 0;
        }
    }
    return false;
}

int main() {
    int n = 9;
    int mat[9][9] =
        {{5, 3, 0, 0, 7, 0, 0, 0, 0},
         {6, 0, 0, 1, 9, 5, 0, 0, 0},
         {0, 9, 8, 0, 0, 0, 0, 6, 0},
         {8, 0, 0, 0, 6, 0, 0, 0, 3},
         {4, 0, 0, 8, 0, 3, 0, 0, 1},
         {7, 0, 0, 0, 2, 0, 0, 0, 6},
         {0, 6, 0, 0, 0, 0, 2, 8, 0},
         {0, 0, 0, 4, 1, 9, 0, 0, 5},
         {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (!solveSudoku(mat, 0, 0, n)) {
        cout << "No solution exists!";
    }
}
