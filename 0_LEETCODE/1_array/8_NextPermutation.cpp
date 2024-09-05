/*

order should be lexigraphical greater if the order is lexigraphical[321]greater then 
the the order should be printed lexigraphical shorter [123]in all cases

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]



Step 1: Find the Rightmost Ascending Pair

Objective: Identify the first element (from right to left) that violates the descending order.

Why: The idea is to find the smallest "break point" where the sequence can be altered to produce 
the next larger permutation.

How:

Traverse the array from right to left.
Find the first index i such that nums[i] < nums[i + 1].
This element nums[i] is where the next permutation can be formed because the sequence 
after nums[i] is in descending order, which is the largest possible order for that 
subsequenc


Step 2: Find the Smallest Number Larger than nums[i] to Swap

Objective: Find the smallest element in the array to the right of nums[i] that
 is larger than nums[i] and swap them.

Why: Swapping with this element ensures that we create the smallest possible permutation 
that is still larger than the current one.

How:

Starting from the rightmost end, find the first element nums[j] such that nums[j] > nums[i].
Swap nums[i] with nums[j].
Step 3: Reverse the Sequence After the Swap
Objective: Reverse the subarray to the right of nums[i].

Why: After swapping, the subarray to the right of nums[i] is still in descending order, 
which is the largest possible permutation for that subarray. Reversing it will give us the 
smallest permutation, which ensures that the permutation we generate is the next in 
lexicographical order.

How:

Reverse the subarray starting from nums[i + 1] to the end of the array.
This ensures that the subarray is now in ascending order, which is the smallest 
possible order and completes the next permutation

*/

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    // Step 1: Find the first decreasing element from the right.
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    // Step 2: If such an element is found, find the next larger element to the right of it.
    if (i >= 0) {
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        // Swap the two elements.
        std::swap(nums[i], nums[j]);
    }

    // Step 3: Reverse the elements to the right of the initially found element.
    std::reverse(nums.begin() + i + 1, nums.end());
}
};



