/*
283. Move Zeroes
Easy
13.8K
348
company
Yandex
company
Apple
company
Amazon

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:

Input: nums = [0]
Output: [0]

 

Constraints:

    1 <= nums.length <= 104
    -231 <= nums[i] <= 231 - 1

 
Follow up: Could you minimize the total number of operations done?
Accepted
2.3M
Submissions
3.7M
Acceptance Rate
61.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (70)
Similar Questions
Remove Element
Easy
Apply Operations to an Array
Easy
Related Topics
Array
Two Pointers
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZero = 0;
        
        for(int i=0; i<nums.size(); i++)
            if(nums[i] != 0)
                swap(nums[i], nums[nonZero++]); // swap all non zero elements to begining of the array
    }
};