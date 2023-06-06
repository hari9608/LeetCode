/*
2553. Separate the Digits in an Array
Easy
316
9
company
Facebook

Given an array of positive integers nums, return an array answer that consists of the digits of each integer in nums after separating them in the same order they appear in nums.

To separate the digits of an integer is to get all the digits it has in the same order.

    For example, for the integer 10921, the separation of its digits is [1,0,9,2,1].

 

Example 1:

Input: nums = [13,25,83,77]
Output: [1,3,2,5,8,3,7,7]
Explanation: 
- The separation of 13 is [1,3].
- The separation of 25 is [2,5].
- The separation of 83 is [8,3].
- The separation of 77 is [7,7].
answer = [1,3,2,5,8,3,7,7]. Note that answer contains the separations in the same order.

Example 2:

Input: nums = [7,1,3,9]
Output: [7,1,3,9]
Explanation: The separation of each integer in nums is itself.
answer = [7,1,3,9].

 

Constraints:

    1 <= nums.length <= 1000
    1 <= nums[i] <= 105

Accepted
39.3K
Submissions
49.5K
Acceptance Rate
79.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (6)
Similar Questions
Count Integers With Even Digit Sum
Easy
Alternating Digit Sum
Easy
Related Topics
Array
Simulation
*/
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> separate_digits;
        for(int i=nums.size()-1; i>=0; i--)
            while(nums[i] > 0)
            {
                separate_digits.push_back(nums[i] % 10);
                nums[i] /= 10;
            }

        reverse(separate_digits.begin(), separate_digits.end());
        return separate_digits;
    }
};