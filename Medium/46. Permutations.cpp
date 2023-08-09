/*
46. Permutations
Medium
17.4K
277
company
Bloomberg
company
Apple
company
Amazon

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:

Input: nums = [1]
Output: [[1]]

 

Constraints:

    1 <= nums.length <= 6
    -10 <= nums[i] <= 10
    All the integers of nums are unique.

Accepted
1.7M
Submissions
2.3M
Acceptance Rate
76.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (68)
Similar Questions
Next Permutation
Medium
Permutations II
Medium
Permutation Sequence
Hard
Combinations
Medium
Related Topics
Array
Backtracking
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permute;
        vector<int> curr = {};

        backtrack(curr, permute, nums);

        return permute;
    }
    
    void backtrack(vector<int>& curr, vector<vector<int>>& permute, vector<int>& nums) {
        if (curr.size() == nums.size()) 
        {
            permute.push_back(curr);
            return;
        }
        
        for (int num: nums) 
        {
            if (find(curr.begin(), curr.end(), num) == curr.end()) 
            {
                curr.push_back(num);
                backtrack(curr, permute, nums);
                curr.pop_back();
            }
        }
    }
};