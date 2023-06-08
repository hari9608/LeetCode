/*
1480. Running Sum of 1d Array
Easy
6.8K
307
company
Google
company
Amazon
company
Adobe

Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].

Example 2:

Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].

Example 3:

Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]

 

Constraints:

    1 <= nums.length <= 1000
    -10^6 <= nums[i] <= 10^6

Accepted
1.5M
Submissions
1.7M
Acceptance Rate
87.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (78)
Related Topics
Array
Prefix Sum
*/
class Solution {
    public int[] runningSum(int[] nums) {
        for(int i=1; i<nums.length; i++)
            nums[i] = nums[i-1]+nums[i];
            
        return nums;
    }
}