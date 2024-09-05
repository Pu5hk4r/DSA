#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0; // Edge case: empty array
        }
        
        int current_sum = nums[0]; // Initialize to the first element
        int largest_sum = nums[0]; // Initialize to the first element
        
        for (int i = 1; i < nums.size(); ++i) {
            current_sum = std::max(nums[i], current_sum + nums[i]); // Compute current_sum
            largest_sum = std::max(largest_sum, current_sum); // Update largest_sum
        }
        
        return largest_sum;
    }
};