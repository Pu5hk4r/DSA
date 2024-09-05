#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void sortRowWise(vector<vector<int>>& matrix) {
    for (auto& row : matrix) {
        sort(row.begin(), row.end());
    }
}

void sortColumnWise(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    // Transpose the matrix
    vector<vector<int>> transposed(cols, vector<int>(rows));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }

    // Sort each row of the transposed matrix
    sortRowWise(transposed);

    // Transpose back to original
    matrix = vector<vector<int>>(cols, vector<int>(rows));
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            matrix[j][i] = transposed[i][j];
        }
    }
}

vector<vector<int>> mergeMatrices(const vector<vector<int>>& topLeft,
                                   const vector<vector<int>>& topRight,
                                   const vector<vector<int>>& bottomLeft,
                                   const vector<vector<int>>& bottomRight) {
    int topRows = topLeft.size();
    int topCols = topLeft[0].size();
    int bottomRows = bottomLeft.size();
    int bottomCols = bottomLeft[0].size();

    vector<vector<int>> merged(topRows + bottomRows, vector<int>(topCols + bottomCols));

    for (int i = 0; i < topRows; ++i) {
        for (int j = 0; j < topCols; ++j) {
            merged[i][j] = topLeft[i][j];
            merged[i][j + topCols] = topRight[i][j];
        }
    }
    for (int i = 0; i < bottomRows; ++i) {
        for (int j = 0; j < bottomCols; ++j) {
            merged[i + topRows][j] = bottomLeft[i][j];
            merged[i + topRows][j + bottomCols] = bottomRight[i][j];
        }
    }

    sortRowWise(merged);
    sortColumnWise(merged);
    return merged;
}

vector<vector<int>> recursiveMergeSort(vector<vector<int>> matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    if (rows <= 1 && cols <= 1) {
        return matrix;
    }

    int midRow = rows / 2;
    int midCol = cols / 2;

    vector<vector<int>> topLeft(midRow, vector<int>(midCol));
    vector<vector<int>> topRight(midRow, vector<int>(cols - midCol));
    vector<vector<int>> bottomLeft(rows - midRow, vector<int>(midCol));
    vector<vector<int>> bottomRight(rows - midRow, vector<int>(cols - midCol));

    for (int i = 0; i < midRow; ++i) {
        for (int j = 0; j < midCol; ++j) {
            topLeft[i][j] = matrix[i][j];
        }
        for (int j = midCol; j < cols; ++j) {
            topRight[i][j - midCol] = matrix[i][j];
        }
    }
    for (int i = midRow; i < rows; ++i) {
        for (int j = 0; j < midCol; ++j) {
            bottomLeft[i - midRow][j] = matrix[i][j];
        }
        for (int j = midCol; j < cols; ++j) {
            bottomRight[i - midRow][j - midCol] = matrix[i][j];
        }
    }

    topLeft = recursiveMergeSort(topLeft);
    topRight = recursiveMergeSort(topRight);
    bottomLeft = recursiveMergeSort(bottomLeft);
    bottomRight = recursiveMergeSort(bottomRight);

    return mergeMatrices(topLeft, topRight, bottomLeft, bottomRight);
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {4, 2, 3, 1},
        {7, 6, 5, 8},
        {15, 11, 14, 12},
        {10, 9, 13, 16}
    };

    vector<vector<int>> sortedMatrix = recursiveMergeSort(matrix);

    cout << "Sorted 2D Array:" << endl;
    printMatrix(sortedMatrix);

    return 0;
}
