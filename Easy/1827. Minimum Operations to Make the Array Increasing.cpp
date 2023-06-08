/*
1827. Minimum Operations to Make the Array Increasing
Easy
984
49
company
Amazon
Deutsche Bank

You are given an integer array nums (0-indexed). In one operation, you can choose an element of the array and increment it by 1.

    For example, if nums = [1,2,3], you can choose to increment nums[1] to make nums = [1,3,3].

Return the minimum number of operations needed to make nums strictly increasing.

An array nums is strictly increasing if nums[i] < nums[i+1] for all 0 <= i < nums.length - 1. An array of length 1 is trivially strictly increasing.

 

Example 1:

Input: nums = [1,1,1]
Output: 3
Explanation: You can do the following operations:
1) Increment nums[2], so nums becomes [1,1,2].
2) Increment nums[1], so nums becomes [1,2,2].
3) Increment nums[2], so nums becomes [1,2,3].

Example 2:

Input: nums = [1,5,2,4,1]
Output: 14

Example 3:

Input: nums = [8]
Output: 0

 

Constraints:

    1 <= nums.length <= 5000
    1 <= nums[i] <= 104

Accepted
69K
Submissions
88.2K
Acceptance Rate
78.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (2)
Similar Questions
Make Array Non-decreasing or Non-increasing
Hard
Maximum Product After K Increments
Medium
Minimum Replacements to Sort the Array
Hard
Related Topics
Array
Greedy
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int len = nums.size();
        int min_num_to_inc = 0;
        for(int i=1; i<len; i++)
        {
            if(nums[i-1]>=nums[i]) 
            {
                min_num_to_inc += nums[i-1] - nums[i] + 1;
                nums[i] = nums[i-1] + 1;
            }
        }
        for(int i=0; i<len; i++) cout << nums[i] << " ";
        return min_num_to_inc;
    }
};