#include <iostream>
#include <vector>

std::vector<int> rotation(std::vector<int> vec, std::size_t n, std::size_t times) {
    // If times is equal to vec.size() or a multiple of vec.size(), return vec as it is
    if (times == n || times % n == 0) {
        return vec;
    }

    std::vector<int> rotatedvec(n);

    times %= n; // Ensure times is within bounds of array size

    for (std::size_t i = 0; i < n; ++i) {
        rotatedvec[(i + times) % n] = vec[i];
    }

    return rotatedvec;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::size_t n = vec.size();
    std::size_t times = 2;

    std::vector<int> rotated = rotation(vec, n, times);

    for (int val : rotated) {
        std::cout << val << " ";
    }

    return 0;
}
