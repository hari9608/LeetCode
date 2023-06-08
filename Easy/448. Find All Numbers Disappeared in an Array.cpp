/*
448. Find All Numbers Disappeared in an Array
Easy
8.5K
436
company
Google
company
Facebook
company
Amazon

Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Example 2:

Input: nums = [1,1]
Output: [2]

 

Constraints:

    n == nums.length
    1 <= n <= 105
    1 <= nums[i] <= n

 

Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
Accepted
736.3K
Submissions
1.2M
Acceptance Rate
60.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (31)
Similar Questions
First Missing Positive
Hard
Find All Duplicates in an Array
Medium
Find Unique Binary String
Medium
Append K Integers With Minimal Sum
Medium
Replace Elements in an Array
Medium
Maximum Number of Integers to Choose From a Range I
Medium
Maximum Number of Integers to Choose From a Range II
Medium
Related Topics
Array
Hash Table
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++)
            if(nums[abs(nums[i])-1] > 0) 
                nums[abs(nums[i])-1] *= -1;

         vector<int> find_disappear;
         
         for(int i=0; i<nums.size(); i++)
            if(nums[i] > 0) find_disappear.push_back(i+1);

         return find_disappear;
    }
};