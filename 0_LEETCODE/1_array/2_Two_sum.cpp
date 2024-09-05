#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> num_map; // Maps value to its index
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // Check if complement exists in the map
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i};
            }
            
            // Store the index of the current element
            num_map[nums[i]] = i;
        }
        
        return {}; // In case no solution is found (though problem guarantees one solution)
    }
};