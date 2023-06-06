/*
2535. Difference Between Element Sum and Digit Sum of an Array
Easy
439
11

You are given a positive integer array nums.

    The element sum is the sum of all the elements in nums.
    The digit sum is the sum of all the digits (not necessarily distinct) that appear in nums.

Return the absolute difference between the element sum and digit sum of nums.

Note that the absolute difference between two integers x and y is defined as |x - y|.

 

Example 1:

Input: nums = [1,15,6,3]
Output: 9
Explanation: 
The element sum of nums is 1 + 15 + 6 + 3 = 25.
The digit sum of nums is 1 + 1 + 5 + 6 + 3 = 16.
The absolute difference between the element sum and digit sum is |25 - 16| = 9.

Example 2:

Input: nums = [1,2,3,4]
Output: 0
Explanation:
The element sum of nums is 1 + 2 + 3 + 4 = 10.
The digit sum of nums is 1 + 2 + 3 + 4 = 10.
The absolute difference between the element sum and digit sum is |10 - 10| = 0.

 

Constraints:

    1 <= nums.length <= 2000
    1 <= nums[i] <= 2000

Accepted
65.6K
Submissions
77.7K
Acceptance Rate
84.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (17)
Similar Questions
Add Digits
Easy
Minimum Sum of Four Digit Number After Splitting Digits
Easy
Related Topics
Array
Math
*/


class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int nums_sum = 0;
        int nums_unit_sum = 0;
        
        for(auto num:nums)
        {
            nums_sum += num;
            while(num>0)
            {
                nums_unit_sum += num%10;
                num /= 10;
            }
        }

        return abs(nums_sum-nums_unit_sum);
    }
};