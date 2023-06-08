/*
404. Sum of Left Leaves
Easy
4.6K
277
company
Amazon
company
Bloomberg
company
Adobe

Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

Example 2:

Input: root = [1]
Output: 0

 

Constraints:

    The number of nodes in the tree is in the range [1, 1000].
    -1000 <= Node.val <= 1000

Accepted
440.8K
Submissions
774.9K
Acceptance Rate
56.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (8)
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)      return 0;
        
        int sum_left_leaves = 0;
        queue<TreeNode*> stack;
        stack.push(root);

        while (!stack.empty()) 
        {
            TreeNode *subRoot = stack.front();
            stack.pop();

            if (subRoot->left && !subRoot->left->left && !subRoot->left->right)
                sum_left_leaves += subRoot->left->val;
        
            if (subRoot->right)     stack.push(subRoot->right);
            if (subRoot->left)      stack.push(subRoot->left);
        }

        return sum_left_leaves; 
    }
};