/*
673. Number of Longest Increasing Subsequence
Medium
6.2K
253
Commvault
company
Amazon
company
Google

Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.

 

Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

Example 2:

Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.

 

Constraints:

    1 <= nums.length <= 2000
    -106 <= nums[i] <= 106

Accepted
199K
Submissions
420.8K
Acceptance Rate
47.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (32)
Similar Questions
Longest Increasing Subsequence
Medium
Longest Continuous Increasing Subsequence
Easy
Longest Increasing Subsequence II
Hard
Related Topics
Array
Dynamic Programming
Binary Indexed Tree
Segment Tree
*/
class Solution {
public:
    int findNumberOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        vector<int> length(n, 1);
        vector<int> count(n, 1);

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < i; j++) 
            {
                if (nums[j] < nums[i]) 
                {
                    if (length[j] + 1 > length[i]) 
                    {
                        length[i] = length[j] + 1;
                        count[i] = 0;
                    }
                    if (length[j] + 1 == length[i]) 
                        count[i] += count[j];
                }
            }
        }

        int maxLength = *max_element(length.begin(), length.end());
        int number_of_LIS = 0;

        for (int i = 0; i < n; i++) 
            if (length[i] == maxLength) 
                number_of_LIS += count[i];

        return number_of_LIS;
    }
};