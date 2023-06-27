/*
1022. Sum of Root To Leaf Binary Numbers
Easy
3.1K
177
company
Amazon
company
Apple

You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.

    For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.

The test cases are generated so that the answer fits in a 32-bits integer.

 

Example 1:

Input: root = [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

Example 2:

Input: root = [0]
Output: 0

 

Constraints:

    The number of nodes in the tree is in the range [1, 1000].
    Node.val is 0 or 1.

Accepted
191.6K
Submissions
261K
Acceptance Rate
73.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (8)
Related Topics
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
    void rootToLeaf(TreeNode* root, int& sum_root_leaf, int curr_val)
    {
        if(root)
        {
            if(root->val)
                curr_val = (curr_val * 2) + 1;
            else
                curr_val = curr_val * 2;
            
            if(!root->left && !root->right)
                sum_root_leaf += curr_val;
                
            rootToLeaf(root->left, sum_root_leaf, curr_val);
            rootToLeaf(root->right, sum_root_leaf, curr_val);
        }
    }

    int sumRootToLeaf(TreeNode* root) {
        int sum_root_leaf = 0;

        rootToLeaf(root, sum_root_leaf, 0);

        return sum_root_leaf;
    }
};