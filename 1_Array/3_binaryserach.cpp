#include <iostream>
#include <vector>
#include <algorithm>

// Function to perform binary search on a sorted vector
int binary_search(std::vector<int>& vec, int key) {
    // Sort the vector
    std::sort(vec.begin(), vec.end());

    size_t l = 0;
    size_t r = vec.size() - 1;

    // Perform binary search
    while (l <= r) {
        size_t mid = l + (r - l) / 2;

        if (vec[mid] == key) {
            return mid;
        } else if (vec[mid] < key) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return -1; // Return -1 if the key is not found
}

int main() {
    // Initialize a vector with values
    std::vector<int> vec {-12, 45, 12, 10, 45, 96, 15, 63};

    int value;

    // Prompt user to enter a key value
    std::cout << "Enter key value: \n";
    std::cin >> value;

    // Perform binary search and get the index
    int index = binary_search(vec, value);

    // Output the result
    if (index != -1) {
        std::cout << value << " found at index " << index << "\n";
    } else {
        std::cout << "Value not found" << "\n";
    }

    return 0;
}
