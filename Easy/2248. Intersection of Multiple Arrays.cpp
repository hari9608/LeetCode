/*
2248. Intersection of Multiple Arrays
Easy
548
26
company
Bloomberg
company
Uber
Given a 2D integer array nums where nums[i] is a non-empty array of distinct positive integers, return the list of integers that are present in each array of nums sorted in ascending order.

 

Example 1:

Input: nums = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]
Output: [3,4]
Explanation: 
The only integers present in each of nums[0] = [3,1,2,4,5], nums[1] = [1,2,3,4], and nums[2] = [3,4,5,6] are 3 and 4, so we return [3,4].

Example 2:

Input: nums = [[1,2,3],[4,5,6]]
Output: []
Explanation: 
There does not exist any integer present both in nums[0] and nums[1], so we return an empty list [].

 

Constraints:

    1 <= nums.length <= 1000
    1 <= sum(nums[i].length) <= 1000
    1 <= nums[i][j] <= 1000
    All the values of nums[i] are unique.

Accepted
52.4K
Submissions
76.6K
Acceptance Rate
68.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (4)
Similar Questions
Intersection of Two Arrays
Easy
Intersection of Two Arrays II
Easy
Find Smallest Common Element in All Rows
Medium
Intersection of Three Sorted Arrays
Easy
Find the Difference of Two Arrays
Easy
Related Topics
Array
Hash Table
Counting
*/
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int num_len = nums.size();
        map<int, int> intersection;
        vector<int> arrays_intersection;

        for(auto num : nums)    for(auto arr : num)    intersection[arr]++;
        
        for(auto count : intersection)  
            if(count.second == num_len)       arrays_intersection.push_back(count.first);
            
        return arrays_intersection;
    }
};