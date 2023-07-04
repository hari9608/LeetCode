/*
137. Single Number II
Medium
6.7K
600
company
Google
company
Amazon
company
Apple

Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,3,2]
Output: 3

Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99

 

Constraints:

    1 <= nums.length <= 3 * 104
    -231 <= nums[i] <= 231 - 1
    Each element in nums appears exactly three times except for one element which appears once.

Accepted
469.6K
Submissions
776K
Acceptance Rate
60.5%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (75)
Similar Questions
Single Number
Easy
Single Number III
Medium
Related Topics
Array
Bit Manipulation
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one_seen = 0;
        int two_seen = 0;

        for(int num : nums)
        {
            one_seen = (one_seen ^ num) & (~two_seen);
            two_seen = (two_seen ^ num) & (~one_seen);
        }

        return one_seen;
    }
};