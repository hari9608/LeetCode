/*
1150. Check If a Number Is Majority Element in a Sorted Array
Easy
393
34
company
Salesforce

Given an integer array nums sorted in non-decreasing order and an integer target, return true if target is a majority element, or false otherwise.

A majority element in an array nums is an element that appears more than nums.length / 2 times in the array.

 

Example 1:

Input: nums = [2,4,5,5,5,5,5,6,6], target = 5
Output: true
Explanation: The value 5 appears 5 times and the length of the array is 9.
Thus, 5 is a majority element because 5 > 9/2 is true.

Example 2:

Input: nums = [10,100,101,101], target = 101
Output: false
Explanation: The value 101 appears 2 times and the length of the array is 4.
Thus, 101 is not a majority element because 2 > 4/2 is false.

 

Constraints:

    1 <= nums.length <= 1000
    1 <= nums[i], target <= 109
    nums is sorted in non-decreasing order.

Accepted
40.1K
Submissions
69.5K
Acceptance Rate
57.6%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (3)
Similar Questions
Majority Element
Easy
Majority Element II
Medium
Related Topics
Array
Binary Search
*/
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int nums_len = nums.size();
        int majority = (nums_len/2) + 1;
        int count = 0;
        for(auto num : nums)    count += target==num;
        return count >= majority;
    }
};