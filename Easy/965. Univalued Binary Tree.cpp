/*
965. Univalued Binary Tree
Easy
1.7K
63
company
Google
Twilio

A binary tree is uni-valued if every node in the tree has the same value.

Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.

 

Example 1:

Input: root = [1,1,1,1,1,null,1]
Output: true

Example 2:

Input: root = [2,2,2,5,2]
Output: false

 

Constraints:

    The number of nodes in the tree is in the range [1, 100].
    0 <= Node.val < 100

Accepted
194.6K
Submissions
278.4K
Acceptance Rate
69.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (3)
Similar Questions
Find All The Lonely Nodes
Easy
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
    void preorder(TreeNode* root, int& val)
    {
        if(root->val != val)
        {
            val = -1;
            return ;
        }

        if(root->left)  preorder(root->left, val);
        if(root->right) preorder(root->right, val);
    }

    bool isUnivalTree(TreeNode* root) {
        int val = root->val;

        preorder(root, val);

        return val != -1;
    }
};