/*
100. Same Tree
Easy
9.5K
191
company
Amazon
company
Adobe
company
Apple

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:

Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:

Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:

Input: p = [1,2,1], q = [1,1,2]
Output: false

 

Constraints:

    The number of nodes in both trees is in the range [0, 100].
    -104 <= Node.val <= 104

Accepted
1.5M
Submissions
2.6M
Acceptance Rate
58.5%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (77)
Related Topics
Tree
Depth-First Search
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> tree_nodes;
        tree_nodes.push({p, q});

        while(!tree_nodes.empty())
        {
            TreeNode* p_node = tree_nodes.top().first;
            TreeNode* q_node = tree_nodes.top().second;
            tree_nodes.pop();

            if(!p_node && !q_node)  
                continue;

            if(!p_node || !q_node || p_node->val != q_node->val)  
                return false;

            tree_nodes.push({p_node->left, q_node->left});
            tree_nodes.push({p_node->right, q_node->right});
        }

        return true;
    }
};