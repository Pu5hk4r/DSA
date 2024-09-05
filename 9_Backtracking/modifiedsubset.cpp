#include <iostream>
#include <vector>
#include <algorithm>

// Function to find all subsets
void findSubsets(char *input, char *output, int i, int j, std::vector<std::string> &subsets) {
    // Base case: end of the input string
    if (input[i] == '\0') {
        output[j] = '\0';  // End the current subset
        subsets.push_back(std::string(output));  // Store the subset
        return;
    }

    // Recursive case
    // 1. Include the ith character in the current subset
    output[j] = input[i];
    findSubsets(input, output, i + 1, j + 1, subsets);

    // 2. Exclude the ith character from the current subset
    findSubsets(input, output, i + 1, j, subsets);
}

// Custom comparator function to sort subsets
bool compare(const std::string &s1, const std::string &s2) {
    // First sort by length
    if (s1.length() != s2.length()) {
        return s1.length() < s2.length();
    }
    // If lengths are the same, sort lexicographically
    return s1 < s2;
}

int main() {
    char input[100];
    char output[100];
    std::vector<std::string> subsets;

    std::cout << "Enter the string: ";
    std::cin >> input;

    findSubsets(input, output, 0, 0, subsets);

    // Sort subsets
    std::sort(subsets.begin(), subsets.end(), compare);

    // Print sorted subsets
    for (const auto &subset : subsets) {
        if (subset.empty()) {
            std::cout << "NULL" << std::endl;
        } else {
            std::cout << subset << std::endl;
        }
    }

    return 0;
}
