/*
894. All Possible Full Binary Trees
Medium
4.7K
312
company
Adobe
company
Amazon
company
Google

Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.

Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.

A full binary tree is a binary tree where each node has exactly 0 or 2 children.

 

Example 1:

Input: n = 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]

Example 2:

Input: n = 3
Output: [[0,0,0]]

 

Constraints:

    1 <= n <= 20

Accepted
155.3K
Submissions
187.6K
Acceptance Rate
82.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (35)
Related Topics
Dynamic Programming
Tree
Recursion
Memoization
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
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) 
            return {};

        vector<vector<TreeNode*>> dp(n + 1);
        dp[1].push_back(new TreeNode(0));

        for (int count = 3; count <= n; count += 2) 
        {
            for (int i = 1; i < count - 1; i += 2) 
            {
                int j = count - 1 - i;

                for (auto left : dp[i]) 
                {
                    for (auto right : dp[j]) 
                    {
                        TreeNode* root = new TreeNode(0, left, right);
                        dp[count].push_back(root);
                    }
                }
            }
        }
        
        return dp[n];
    }
};