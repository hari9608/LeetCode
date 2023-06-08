/*
136. Single Number
Easy
14K
543
company
Google
company
Amazon
company
Apple

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1

Example 2:

Input: nums = [4,1,2,1,2]
Output: 4

Example 3:

Input: nums = [1]
Output: 1

 

Constraints:

    1 <= nums.length <= 3 * 104
    -3 * 104 <= nums[i] <= 3 * 104
    Each element in the array appears twice except for one element which appears only once.

Accepted
2.2M
Submissions
3.1M
Acceptance Rate
70.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (68)
Similar Questions
Single Number II
Medium
Single Number III
Medium
Missing Number
Easy
Find the Duplicate Number
Medium
Find the Difference
Easy
Related Topics
Array
Bit Manipulation
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0;
        for(i=0; i<nums.size()-1; i+=2){
            if(nums[i]!=nums[i+1]){
                return nums[i];
            }
        }
        return nums[i];

    }
};