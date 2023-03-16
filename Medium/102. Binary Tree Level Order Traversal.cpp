/*
102. Binary Tree Level Order Traversal
Medium
12.6K
249
company
Bloomberg
company
Amazon
company
LinkedIn

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

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
1.7M
Submissions
2.7M
Acceptance Rate
64.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (33)
Similar Questions
Binary Tree Zigzag Level Order Traversal
Medium
Binary Tree Level Order Traversal II
Medium
Minimum Depth of Binary Tree
Easy
Binary Tree Vertical Order Traversal
Medium
Average of Levels in Binary Tree
Easy
N-ary Tree Level Order Traversal
Medium
Cousins in Binary Tree
Easy
Minimum Number of Operations to Sort a Binary Tree by Level
Medium
Divide Nodes Into the Maximum Number of Groups
Hard
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
    vector<vector<int>> levelOrder(TreeNode* root) {
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

        return level_order;
    }
};