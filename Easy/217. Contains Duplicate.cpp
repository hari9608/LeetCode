/*
217. Contains Duplicate
Easy
9.4K
1.2K
company
Apple
company
Uber
company
Amazon

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]
Output: true

Example 2:

Input: nums = [1,2,3,4]
Output: false

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

 

Constraints:

    1 <= nums.length <= 105
    -109 <= nums[i] <= 109

Accepted
2.8M
Submissions
4.6M
Acceptance Rate
61.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (157)
Similar Questions
Contains Duplicate II
Easy
Contains Duplicate III
Hard
Make Array Zero by Subtracting Equal Amounts
Easy
Related Topics
Array
Hash Table
Sorting
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> unique(nums.begin(), nums.end());

        return unique.size() != nums.size();
    }
};
    /*
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i++)
            if(nums[i] == nums[i+1])
                return true;
                
        return false;
    */