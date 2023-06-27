/*
1027. Longest Arithmetic Subsequence
Medium
4.2K
188
company
Adobe
company
Amazon
company
Microsoft

Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.

Note that:

    A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
    A sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).

 

Example 1:

Input: nums = [3,6,9,12]
Output: 4
Explanation:  The whole array is an arithmetic sequence with steps of length = 3.

Example 2:

Input: nums = [9,4,7,2,10]
Output: 3
Explanation:  The longest arithmetic subsequence is [4,7,10].

Example 3:

Input: nums = [20,1,15,3,10,5,8]
Output: 4
Explanation:  The longest arithmetic subsequence is [20,15,10,5].

 

Constraints:

    2 <= nums.length <= 1000
    0 <= nums[i] <= 500

Accepted
148.9K
Submissions
302.8K
Acceptance Rate
49.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (69)
Similar Questions
Destroy Sequential Targets
Medium
Related Topics
Array
Hash Table
Binary Search
Dynamic Programming
*/

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int nums_len = nums.size();
        int longest_arith_seq_length = 0;

        vector<map<int, int>> subsequence(nums_len);
        
        for(int right = 1; right < nums_len; right++)
        {
            for(int left = 0; left < right; left++)
            {            
                int diff =  nums[right] - nums[left];
                int count = 1;

                if(subsequence[left].count(diff))
                    count = subsequence[left][diff]; 
                    
                subsequence[right][diff] = count + 1;

                longest_arith_seq_length = max(longest_arith_seq_length, subsequence[right][diff]);
            }
        }

        return longest_arith_seq_length;
    }
};   