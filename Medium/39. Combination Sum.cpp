/*
39. Combination Sum
Medium
15.6K
310
company
Airbnb
company
Adobe
company
Microsoft

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the
frequency
of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:

Input: candidates = [2], target = 1
Output: []

 

Constraints:

    1 <= candidates.length <= 30
    2 <= candidates[i] <= 40
    All elements of candidates are distinct.
    1 <= target <= 40

Accepted
1.4M
Submissions
2.1M
Acceptance Rate
68.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (43)
Similar Questions
Letter Combinations of a Phone Number
Medium
Combination Sum II
Medium
Combinations
Medium
Combination Sum III
Medium
Factor Combinations
Medium
Combination Sum IV
Medium
Related Topics
Array
Backtracking
*/

class Solution {
public:
    void find_combination(int index, vector<int>& candidates, int target, vector<int> &temp, vector<vector<int>>& combination_sum)
    {
        if(!target)
        {
            combination_sum.push_back(temp);
            return;
        }

        if(target < 0)  return;

        if(index == candidates.size())  return;

        find_combination(index + 1, candidates, target, temp, combination_sum);

        temp.push_back(candidates[index]);
        find_combination(index, candidates, target - candidates[index], temp, combination_sum);
        temp.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combination_sum;
        vector<int> temp;

        find_combination(0, candidates, target, temp, combination_sum);

        return combination_sum;
    }
};