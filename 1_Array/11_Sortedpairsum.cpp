/*

{10, 22, 28, 29, 30, 40}, x = 54


Sample Output

22 and 30
*/

#include <bits/stdc++.h>
using namespace std;

pair<int, int> closestSum(vector<int> vec, int val) {
    // Sort the array
    sort(vec.begin(), vec.end());

    int left = 0;
    int right = vec.size() - 1;
    pair<int, int> closestPair;
    int minDiff = INT_MAX;

    // Use two-pointer technique
    while (left < right) {
        int sum = vec[left] + vec[right];
        int diff = abs(sum - val);

        if (diff < minDiff) {
            minDiff = diff;
            closestPair = {vec[left], vec[right]};
        }

        // Move pointers based on comparison with target value
        if (sum < val) {
            left++;
        } else {
            right--;
        }
    }

    return closestPair;
}

int main() {
    vector<int> vec = {10, 22, 28, 29, 30, 40};
    int val = 54;

    pair<int, int> result = closestSum(vec, val);
    cout << "The pair with the closest sum to " << val << " is (" << result.first << ", " << result.second << ")" << endl;

    return 0;
}
