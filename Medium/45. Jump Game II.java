/*
45. Jump Game II
Medium
12.1K
420
company
Amazon
company
Apple
company
Google

You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

    0 <= j <= nums[i] and
    i + j < n

Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [2,3,0,1,4]
Output: 2

 

Constraints:

    1 <= nums.length <= 104
    0 <= nums[i] <= 1000
    It's guaranteed that you can reach nums[n - 1].

Accepted
872.7K
Submissions
2.2M
Acceptance Rate
39.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (69)
Similar Questions
Jump Game
Medium
Jump Game III
Medium
Jump Game VII
Medium
Jump Game VIII
Medium
Minimum Number of Visited Cells in a Grid
Hard
Related Topics
Array
Dynamic Programming
Greedy
*/

class Solution {
    public int jump(int[] nums) {
        int jumps = 0;
        int n = nums.length;
        int end = 0;
        int far = 0;

        for(int i=0; i<n-1; i++)
        {
            far = Math.max(far, i + nums[i]);
            if(i == end)    
            {   
                jumps++;
                end = far;
            }
        }

        return jumps;
    }
}