#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        
        // Step 1: Find the pivot
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }
        
        if (i >= 0) {
            // Step 2: Find the successor to pivot
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                --j;
            }
            std::swap(nums[i], nums[j]);
        }
        
        // Step 3: Reverse the suffix
        std::reverse(nums.begin() + i + 1, nums.end());
    }
};