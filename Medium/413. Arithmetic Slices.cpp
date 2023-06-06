/*
413. Arithmetic Slices
Medium
4.9K
279
company
Google
company
Bloomberg
company
Amazon

An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

    For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.

Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.

 

Example 1:

Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.

Example 2:

Input: nums = [1]
Output: 0

 

Constraints:

    1 <= nums.length <= 5000
    -1000 <= nums[i] <= 1000

Accepted
276.8K
Submissions
425.5K
Acceptance Rate
65.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (12)
Similar Questions
Arithmetic Slices II - Subsequence
Hard
Arithmetic Subarrays
Medium
Number of Zero-Filled Subarrays
Medium
Length of the Longest Alphabetical Continuous Substring
Medium
Related Topics
Array
Dynamic Programming
*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int> dp(nums.size());
        int number_of_arithmetic_slices = 0;

        for (int i = 2; i < dp.size(); i++)
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) 
            {
                dp[i] = 1 + dp[i - 1];
                number_of_arithmetic_slices += dp[i];
            }
        
        return number_of_arithmetic_slices;
    }
};