#include <iostream>
#include <vector>

std::vector<std::vector<int>> generatePascalsTriangle(int n) {
    std::vector<std::vector<int>> triangle;

    for (int i = 0; i < n; ++i) {
        std::vector<int> row(i + 1, 1); // Create a row with all elements set to 1

        // Update the row elements based on the previous row
        for (int j = 1; j < i; ++j) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        // Add the current row to the triangle
        triangle.push_back(row);
    }

    return triangle;
}

void printPascalsTriangle(const std::vector<std::vector<int>>& triangle) {
    for (const auto& row : triangle) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Enter the number of rows for Pascal's Triangle: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Number of rows should be a positive integer." << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> triangle = generatePascalsTriangle(n);
    printPascalsTriangle(triangle);

    return 0;
}
