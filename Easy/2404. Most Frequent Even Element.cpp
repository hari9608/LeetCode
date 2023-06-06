/*
2404. Most Frequent Even Element
Easy
676
25

Given an integer array nums, return the most frequent even element.

If there is a tie, return the smallest one. If there is no such element, return -1.

 

Example 1:

Input: nums = [0,1,2,2,4,4,1]
Output: 2
Explanation:
The even elements are 0, 2, and 4. Of these, 2 and 4 appear the most.
We return the smallest one, which is 2.

Example 2:

Input: nums = [4,4,4,9,2,4]
Output: 4
Explanation: 4 is the even element appears the most.

Example 3:

Input: nums = [29,47,21,41,13,37,25,7]
Output: -1
Explanation: There is no even element.

 

Constraints:

    1 <= nums.length <= 2000
    0 <= nums[i] <= 105

Accepted
51.3K
Submissions
101K
Acceptance Rate
50.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (7)
Similar Questions
Majority Element
Easy
Majority Element II
Medium
Top K Frequent Elements
Medium
Sort Characters By Frequency
Medium
Related Topics
Array
Hash Table
Counting
*/
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> nums_map;

        for(auto num:nums)
            if(!(num & 1))
                nums_map[num]++;

        int res = -1;
        int ans = -1;
        
        for(auto m : nums_map)
            if(res < m.second)
            {
                ans = m.first;
                res = m.second;
            }
        
        return res ? ans : -1;
    }
};