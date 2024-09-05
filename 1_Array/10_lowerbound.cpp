#include<bits/stdc++.h>
using namespace std;


int lowerBound(vector<int> A, int Val) {
    int low = 0;
    int high = A.size() - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (A[mid] == Val) {
            return Val; // Exact match found
        } else if (A[mid] < Val) {
            result = A[mid]; // Update result to current element
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}