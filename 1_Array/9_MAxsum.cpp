#include<bits/stdc++.h>
using namespace std;

int maxSumSubarray(vector<int> vec) {
     bool allnegative = true;
    int largest = INT_MIN;

    // Check for all negative elements and find the largest element
    for (const auto &x : vec) {
        if (x > 0) {
            allnegative = false;
        }
        largest = max(largest, x);
    }

    // If all elements are negative, return the largest element
    if (allnegative) {
        return largest;
    }

    int cs = 0; // Current sum
    int ans = INT_MIN; // Initialize ans to a very small number

    // Main loop to find the maximum subarray sum
    for (const auto &x : vec) {
        cs += x;
        if (cs < 0) {
            cs = 0;
        }
        ans = max(ans, cs);
    }

    return ans;
}