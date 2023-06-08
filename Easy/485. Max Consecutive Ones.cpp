/*
485. Max Consecutive Ones
Easy
4.5K
430
company
Adobe
company
Google
company
Amazon

Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2

 

Constraints:

    1 <= nums.length <= 105
    nums[i] is either 0 or 1.

Accepted
879.4K
Submissions
1.5M
Acceptance Rate
56.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (18)
Similar Questions
Max Consecutive Ones II
Medium
Max Consecutive Ones III
Medium
Consecutive Characters
Easy
Longer Contiguous Segments of Ones than Zeros
Easy
Length of the Longest Alphabetical Continuous Substring
Medium
Maximum Enemy Forts That Can Be Captured
Easy
Related Topics
Array
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0;
        int curr_count = 0;
        for(auto val:nums)
        {
            curr_count = val==1?curr_count+1:0;
            result = curr_count>result?curr_count:result;
        }
        return result;
    }
};