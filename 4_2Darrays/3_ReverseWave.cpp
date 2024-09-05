#include <iostream>
#include <vector>

std::vector<int> reverseWaveForm(const std::vector<std::vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return {};

    int m = matrix.size();
    int n = matrix[0].size();
    std::vector<int> result;

    for (int col = n - 1; col >= 0; --col) {
        if (col % 2 == 1) {
            for (int row = 0; row < m; ++row) {
                result.push_back(matrix[row][col]);
            }
        } else {
            for (int row = m - 1; row >= 0; --row) {
                result.push_back(matrix[row][col]);
            }
        }
    }

    return result;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    std::vector<int> result = reverseWaveForm(matrix);

    for (int num : result) {
        std::cout << num << " ";
    }

    return 0;
}
