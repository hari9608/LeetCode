/*
724. Find Pivot Index
Easy
7.1K
758
company
Amazon
company
Facebook
company
Apple

Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

 

Example 1:

Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11

Example 2:

Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.

Example 3:

Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0

 

Constraints:

    1 <= nums.length <= 104
    -1000 <= nums[i] <= 1000

 

Note: This question is the same as 1991: https://leetcode.com/problems/find-the-middle-index-in-array/
Accepted
852.2K
Submissions
1.5M
Acceptance Rate
55.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (97)
Similar Questions
Subarray Sum Equals K
Medium
Find the Middle Index in Array
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
    public int pivotIndex(int[] nums) {
        int total_sum = 0;
        int left_sum = 0;

        for(int ind = 0; ind < nums.length; ind++)  total_sum = total_sum + nums[ind];
        for(int ind = 0; ind < nums.length; ind++)
        {
            if(left_sum == total_sum - left_sum - nums[ind])    return ind;
            left_sum = left_sum + nums[ind];
        }

        return -1;
    }
}