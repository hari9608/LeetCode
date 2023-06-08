/*
1991. Find the Middle Index in Array
Easy
1.1K
49
company
Facebook
company
Adobe
company
tcs

Given a 0-indexed integer array nums, find the leftmost middleIndex (i.e., the smallest amongst all the possible ones).

A middleIndex is an index where nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1].

If middleIndex == 0, the left side sum is considered to be 0. Similarly, if middleIndex == nums.length - 1, the right side sum is considered to be 0.

Return the leftmost middleIndex that satisfies the condition, or -1 if there is no such index.

 

Example 1:

Input: nums = [2,3,-1,8,4]
Output: 3
Explanation: The sum of the numbers before index 3 is: 2 + 3 + -1 = 4
The sum of the numbers after index 3 is: 4 = 4

Example 2:

Input: nums = [1,-1,4]
Output: 2
Explanation: The sum of the numbers before index 2 is: 1 + -1 = 0
The sum of the numbers after index 2 is: 0

Example 3:

Input: nums = [2,5]
Output: -1
Explanation: There is no valid middleIndex.

 

Constraints:

    1 <= nums.length <= 100
    -1000 <= nums[i] <= 1000

 

Note: This question is the same as 724: https://leetcode.com/problems/find-pivot-index/
Accepted
65.4K
Submissions
97.3K
Acceptance Rate
67.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (5)
Similar Questions
Find Pivot Index
Easy
Partition Array Into Three Parts With Equal Sum
Easy
Number of Ways to Split Array
Medium
Maximum Sum Score of Array
Medium
Left and Right Sum Differences
Easy
Related Topics
Array
Prefix Sum
*/
class Solution {
    public int findMiddleIndex(int[] nums) {
        int nums_len = nums.length;
        int middle_index = -1;
        int[] prefix_sum = new int[nums_len];

        prefix_sum[0] = nums[0];

        for(int ind = 1; ind < nums_len; ind++)
            prefix_sum[ind] = prefix_sum[ind - 1] + nums[ind];

        int num_sum = prefix_sum[nums_len - 1];

        if(num_sum - nums[0] == 0 || nums_len == 1)
                return 0;

        for(int ind = 1; ind < nums_len; ind++)
            if(prefix_sum[ind - 1] == num_sum - prefix_sum[ind])
                return ind;
    
        return middle_index;
    }
}