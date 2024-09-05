#include <iostream>
using namespace std;

bool canPlace(int board[][20], int n, int x, int y) {
    // Check the column
    for (int k = 0; k < x; k++) {
        if (board[k][y] == 1) {
            return false;
        }
    }
    // Check the left diagonal
    int i = x;
    int j = y;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 1) {
            return false;
        }
        i--;
        j--;
    }

    // Check the right diagonal
    i = x;
    j = y;
    while (i >= 0 && j < n) {
        if (board[i][j] == 1) {
            return false;
        }
        i--;
        j++;
    }
    return true;
}

void printBoard(int n, int board[][20]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void solveNQueen(int n, int board[][20], int i, int &solutionCount) {
    // Base case: All queens are placed
    if (i == n) {
        // Print the board
        cout << "Solution " << ++solutionCount << ":\n";
        printBoard(n, board);
        return;
    }

    // Recursive case: Try placing a queen in every column of row i
    for (int j = 0; j < n; j++) {
        if (canPlace(board, n, i, j)) {
            board[i][j] = 1;
            solveNQueen(n, board, i + 1, solutionCount);
            // Backtrack
            board[i][j] = 0;
        }
    }
}

int main() {
    int board[20][20] = {0};
    int n;
    cout << "Enter the size of the board (n): ";
    cin >> n;

    if (n <= 0 || n > 20) {
        cout << "Invalid board size. Please enter a value between 1 and 20." << endl;
        return 1;
    }

    int solutionCount = 0;
    solveNQueen(n, board, 0, solutionCount);

    if (solutionCount == 0) {
        cout << "No solution exists for the given board size." << endl;
    }

    return 0;
}
