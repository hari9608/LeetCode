/*
128. Longest Consecutive Sequence
Medium
16.3K
682
company
Amazon
company
Google
company
Bloomberg

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

 

Constraints:

    0 <= nums.length <= 105
    -109 <= nums[i] <= 109

Accepted
1.1M
Submissions
2.4M
Acceptance Rate
48.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (53)
Similar Questions
Binary Tree Longest Consecutive Sequence
Medium
Find Three Consecutive Integers That Sum to a Given Number
Medium
Maximum Consecutive Floors Without Special Floors
Medium
Length of the Longest Alphabetical Continuous Substring
Medium
Related Topics
Array
Hash Table
Union Find
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size())    
            return 0;

        set<int> unique_num(nums.begin(), nums.end());
        int longest_consecutive = 1;

        for(int num : unique_num)
            if(!unique_num.count(num - 1))
            {
                int current_consecutive = 1;

                while(unique_num.count(num + 1))
                {
                    current_consecutive++;
                    num++;
                }
                
                longest_consecutive = max(longest_consecutive, current_consecutive);
            }
    
        return longest_consecutive;
    }
};