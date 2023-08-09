/*
95. Unique Binary Search Trees II
Medium
7.1K
466
company
Uber
company
Adobe
company
Bloomberg

Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

 

Example 1:

Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

Example 2:

Input: n = 1
Output: [[1]]

 

Constraints:

    1 <= n <= 8

Accepted
410.3K
Submissions
733.6K
Acceptance Rate
55.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (45)
Similar Questions
Unique Binary Search Trees
Medium
Different Ways to Add Parentheses
Medium
Related Topics
Dynamic Programming
Backtracking
Tree
Binary Search Tree
Binary Tree
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> allPossibleBST(int start, int end, map<pair<int, int>, vector<TreeNode*>>& memo) {
        vector<TreeNode*> res;

        if (start > end) 
        {
            res.push_back(nullptr);
            return res;
        }

        if (memo.find(make_pair(start, end)) != memo.end()) 
            return memo[make_pair(start, end)];
        
        for (int i = start; i <= end; ++i) 
        {
            vector<TreeNode*> leftSubTrees = allPossibleBST(start, i - 1, memo);
            vector<TreeNode*> rightSubTrees = allPossibleBST(i + 1, end, memo);

            for (auto left: leftSubTrees) 
            {
                for (auto right: rightSubTrees) 
                {
                    TreeNode* root = new TreeNode(i, left, right);
                    res.push_back(root);
                }
            }
        }

        return memo[make_pair(start, end)] = res;
    }

    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> memo;
        
        return allPossibleBST(1, n, memo);
    }
};