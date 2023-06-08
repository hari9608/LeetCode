/*
1133. Largest Unique Number
Easy
280
16
company
Amazon

Given an integer array nums, return the largest integer that only occurs once. If no integer occurs once, return -1.

 

Example 1:

Input: nums = [5,7,3,9,4,9,8,3,1]
Output: 8
Explanation: The maximum integer in the array is 9 but it is repeated. The number 8 occurs only once, so it is the answer.

Example 2:

Input: nums = [9,9,8,8]
Output: -1
Explanation: There is no number that occurs only once.

 

Constraints:

    1 <= nums.length <= 2000
    0 <= nums[i] <= 1000

Accepted
41.3K
Submissions
60.9K
Acceptance Rate
67.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (0)
Related Topics
Array
Hash Table
Sorting
*/
class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        map<int, int> number_map;

        for(auto num : nums)    
            number_map[-num]++;

        for(auto unique : number_map)   
            if(unique.second == 1)      
                return -1 * unique.first;

        return -1;
    }
};