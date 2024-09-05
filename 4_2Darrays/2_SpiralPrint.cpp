#include <iostream>
#include <vector>

void printSpiral(const std::vector<std::vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return; // Handle empty matrix case
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

    int top = 0, bottom = rows - 1; // top = startrow bottom = endrow   left = startcol  right endcol
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
        // Print top row
        for (int i = left; i <= right; ++i) {
            std::cout << matrix[top][i] << " ";
        }
        ++top;

        // Print right column
        for (int i = top; i <= bottom; ++i) {
            std::cout << matrix[i][right] << " ";
        }
        --right;

        if (top <= bottom) {
            // Print bottom row
            for (int i = right; i >= left; --i) {
                std::cout << matrix[bottom][i] << " ";
            }
            --bottom;
        }

        if (left <= right) {
            // Print left column
            for (int i = bottom; i >= top; --i) {
                std::cout << matrix[i][left] << " ";
            }
            ++left;
        }
    }
}

int main() {
    std::vector<std::vector<int>> matrix = {
        { 1,  2,  3,  4 },
        { 5,  6,  7,  8 },
        { 9, 10, 11, 12 },
        {13, 14, 15, 16}
    };

    printSpiral(matrix);

    return 0;
}
