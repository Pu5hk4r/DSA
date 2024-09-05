#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> makeZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> rowMarker(rows, 0);
    vector<int> colMarker(cols, 0);

    // Step 1: Identify rows and columns to be zeroed
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                rowMarker[i] = 1;
                colMarker[j] = 1;
            }
        }
    }

    // Step 2: Zero out the identified rows
    for (int i = 0; i < rows; ++i) {
        if (rowMarker[i] == 1) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = 0;
            }
        }
    }

    // Step 3: Zero out the identified columns
    for (int j = 0; j < cols; ++j) {
        if (colMarker[j] == 1) {
            for (int i = 0; i < rows; ++i) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

int main() {
    vector<vector<int>> matrix = {
        {5, 4, 3, 9},
        {2, 0, 7, 6},
        {1, 3, 4, 0},
        {9, 8, 3, 4}
    };
    
    vector<vector<int>> result = makeZeroes(matrix);
    
    for (const auto& row : result) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    
    return 0;
}
