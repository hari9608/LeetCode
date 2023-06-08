/*
94. Binary Tree Inorder Traversal
Easy
11.6K
588
company
Amazon
company
Adobe
company
Google

Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [1]
Output: [1]

 

Constraints:

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100

 
Follow up: Recursive solution is trivial, could you do it iteratively?
Accepted
2M
Submissions
2.7M
Acceptance Rate
74.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (53)
Similar Questions
Validate Binary Search Tree
Medium
Binary Tree Preorder Traversal
Easy
Binary Tree Postorder Traversal
Easy
Binary Search Tree Iterator
Medium
Kth Smallest Element in a BST
Medium
Closest Binary Search Tree Value II
Hard
Inorder Successor in BST
Medium
Convert Binary Search Tree to Sorted Doubly Linked List
Medium
Minimum Distance Between BST Nodes
Easy
Related Topics
Stack
Tree
Depth-First Search
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
    void traverse(TreeNode* root, vector<int>& ans)
    {
        if(root==NULL)      
            return;

        traverse(root->left, ans);
        ans.push_back(root->val); 
        traverse(root->right, ans);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder_traversal;
        traverse(root, inorder_traversal);

        return inorder_traversal;
    }
};