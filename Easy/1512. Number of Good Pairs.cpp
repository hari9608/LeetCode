/*
1512. Number of Good Pairs
Easy
3.9K
193
company
Amazon
company
Adobe
company
Apple

Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.

 

Example 1:

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

Example 2:

Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.

Example 3:

Input: nums = [1,2,3]
Output: 0

 

Constraints:

    1 <= nums.length <= 100
    1 <= nums[i] <= 100

Accepted
450.9K
Submissions
511.2K
Acceptance Rate
88.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (32)
Similar Questions
Number of Pairs of Interchangeable Rectangles
Medium
Substrings That Begin and End With the Same Letter
Medium
Related Topics
Array
Hash Table
Math
Counting
*/
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> num_fre;
        int good_pairs = 0;
        for(auto num : nums)    num_fre[num]++;

        for(auto fre : num_fre)
        {
            int temp = fre.second;
            good_pairs += (temp*(temp-1))/2;
        }
        return good_pairs;
    }
};