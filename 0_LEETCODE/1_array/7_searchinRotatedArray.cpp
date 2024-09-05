/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot
 index k (1 <= k < nums.length) such that the 
 resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
 For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 
 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, 
return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104*/


//key idea the point where the law of ascending order is break that point
// is the pivot point where was the array is rotated

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;  // Start index
        int e = nums.size() - 1;  // End index

        while (s <= e) {
            int mid = s + (e - s) / 2;  // Avoid potential overflow

            if (nums[mid] == target) {
                return mid;
            }

            // Check if the left half is sorted
            if (nums[s] <= nums[mid]) {
                // If target is in the left half
                if (target >= nums[s] && target < nums[mid]) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            } 
            // Otherwise, the right half must be sorted
            else {
                // If target is in the right half
                if (target > nums[mid] && target <= nums[e]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }

        return -1;  // Target not found
    }
};
