/*
700. Search in a Binary Search Tree
Easy
5K
167
company
Adobe
company
Microsoft
company
Amazon

You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

 

Example 1:

Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]

Example 2:

Input: root = [4,2,7,1,3], val = 5
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [1, 5000].
    1 <= Node.val <= 107
    root is a binary search tree.
    1 <= val <= 107

Accepted
651.6K
Submissions
835.9K
Acceptance Rate
77.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (17)
Similar Questions
Closest Binary Search Tree Value
Easy
Insert into a Binary Search Tree
Medium
Closest Nodes Queries in a Binary Search Tree
Medium
Related Topics
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
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root && val != root->val)
            root = val < root->val ? root->left : root->right;

        return root;
    }
};