/*
235. Lowest Common Ancestor of a Binary Search Tree
Medium
9.2K
258
company
Amazon
company
LinkedIn
company
Facebook

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Example 3:

Input: root = [2,1], p = 2, q = 1
Output: 2

 

Constraints:

    The number of nodes in the tree is in the range [2, 105].
    -109 <= Node.val <= 109
    All Node.val are unique.
    p != q
    p and q will exist in the BST.

Accepted
1.2M
Submissions
1.9M
Acceptance Rate
61.6%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (23)
Similar Questions
Lowest Common Ancestor of a Binary Tree
Medium
Smallest Common Region
Medium
Lowest Common Ancestor of a Binary Tree II
Medium
Lowest Common Ancestor of a Binary Tree III
Medium
Lowest Common Ancestor of a Binary Tree IV
Medium
Related Topics
Tree
Depth-First Search
Binary Search Tree
Binary Tree
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pVal = p->val;
        int qVal = q->val;

        TreeNode* node = root;

        while (node) 
        {
            int parentVal = node->val;

            if      (pVal > parentVal && qVal > parentVal)      node = node->right;
            else if (pVal < parentVal && qVal < parentVal)      node = node->left;
            else                                                return node;
        }

        return NULL;
    }
};