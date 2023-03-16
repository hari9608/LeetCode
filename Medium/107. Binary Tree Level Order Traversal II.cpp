/*
107. Binary Tree Level Order Traversal II
Medium
4.2K
308
company
Amazon
company
Apple

Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 2000].
    -1000 <= Node.val <= 1000

Accepted
568K
Submissions
930.3K
Acceptance Rate
61.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (8)
Similar Questions
Binary Tree Level Order Traversal
Medium
Average of Levels in Binary Tree
Easy
Related Topics
Tree
Breadth-First Search
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> level_order;
        queue<TreeNode*> levels;
        if(root)    levels.push(root);
        while(!levels.empty())
        {
            vector<int> level;
            int lev_len = levels.size();
            for(int i=0; i<lev_len; i++)
            {
                TreeNode* temp = levels.front();    levels.pop();
                if(temp->left)      levels.push(temp->left);
                if(temp->right)     levels.push(temp->right);
                level.push_back(temp->val);
            }
            level_order.push_back(level);
        }
        reverse(level_order.begin(), level_order.end());
        
        return level_order;
    }
};