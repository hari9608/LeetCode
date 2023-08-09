/*
77. Combinations
Medium
7.5K
206
company
Amazon
company
Adobe
company
Bloomberg

Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.

Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.

 

Constraints:

    1 <= n <= 20
    1 <= k <= n

Accepted
765.1K
Submissions
1.1M
Acceptance Rate
68.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (50)
Similar Questions
Combination Sum
Medium
Permutations
Medium
Related Topics
Backtracking
*/

class Solution {
public:
    void backtrack(int n, int k, int first, vector<int>& curr, vector<vector<int>>& combined){
        if(curr.size() == k)
        {
            combined.push_back(curr);
            return;
        }

        int need = k - curr.size();
        int remain = n - first + 1;
        int avail = remain - need;

        for(int num = first; num <= first + avail; num++)
        {
            curr.push_back(num);
            backtrack(n, k, num + 1, curr, combined);
            curr.pop_back();
        }

        return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combined;
        vector<int> curr;

        backtrack(n, k, 1, curr, combined);

        return combined;
    }
};