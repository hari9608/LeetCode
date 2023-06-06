/*
300. Longest Increasing Subsequence
Medium
17.4K
327
company
Google
company
Amazon
company
TikTok

Given an integer array nums, return the length of the longest strictly increasing
subsequence
.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1

 

Constraints:

    1 <= nums.length <= 2500
    -104 <= nums[i] <= 104

 

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
Accepted
1.2M
Submissions
2.3M
Acceptance Rate
52.5%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (37)
Similar Questions
Increasing Triplet Subsequence
Medium
Russian Doll Envelopes
Hard
Maximum Length of Pair Chain
Medium
Number of Longest Increasing Subsequence
Medium
Minimum ASCII Delete Sum for Two Strings
Medium
Minimum Number of Removals to Make Mountain Array
Hard
Find the Longest Valid Obstacle Course at Each Position
Hard
Minimum Operations to Make the Array K-Increasing
Hard
Longest Ideal Subsequence
Medium
Maximum Number of Books You Can Take
Hard
Longest Increasing Subsequence II
Hard
Related Topics
Array
Binary Search
Dynamic Programming
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int lengthof_lis = 0;
        
        for (int i = 1; i < nums.size(); i++) 
            for (int j = 0; j < i; j++) 
                if (nums[i] > nums[j])  dp[i] = max(dp[i], dp[j] + 1);
                    
        for (int c: dp)     lengthof_lis = max(lengthof_lis, c);
        
        return lengthof_lis;
    }
};