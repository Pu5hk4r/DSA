#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int PrefixSum(int *arr, int n) {
    // Create prefix sum array
    int *prefix = new int[n];
    prefix[0] = arr[0];

    for (size_t i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    int largest_sum = INT_MIN;

    // Find the largest sum of subarrays
    for (size_t i = 0; i < n; i++) {
        for (size_t j = i; j < n; j++) {
            int subarray_sum = i > 0 ? prefix[j] - prefix[i - 1] : prefix[j];
            largest_sum = max(largest_sum, subarray_sum);
        }
    }

    // Clean up dynamically allocated memory
    delete[] prefix;

    return largest_sum;
}

int main() {
    int arr[] = {10, 15, 12, 9, 6, 4, 3, 10, 8};
    int n = sizeof(arr) / sizeof(int);

    int sum = PrefixSum(arr, n);
    if (sum != -1) {
        cout << "The largest subarray sum is " << sum << endl;
    } else {
        cout << "Sum is NOT Found!" << endl;
    }

    return 0;
}
