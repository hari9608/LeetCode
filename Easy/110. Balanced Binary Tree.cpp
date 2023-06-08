/*
110. Balanced Binary Tree
Easy
9.1K
509
company
Amazon
company
Facebook
company
Bloomberg

Given a binary tree, determine if it is
height-balanced
.

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:

Input: root = []
Output: true

 

Constraints:

    The number of nodes in the tree is in the range [0, 5000].
    -104 <= Node.val <= 104

Accepted
1.1M
Submissions
2.3M
Acceptance Rate
49.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (49)
Similar Questions
Maximum Depth of Binary Tree
Easy
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
    bool isBalancedHelpper(TreeNode* root, int& height){
        if(root == NULL)
        {
            height = -1;
            return true;
        }

        int left, right;

        if(isBalancedHelpper(root->left, left) && isBalancedHelpper(root->right, right) && abs(left - right) < 2)
        {
            height = max(left, right) + 1;
            return true;
        }
        
        return false;
    }

    bool isBalanced(TreeNode* root) {
        int height;
        return isBalancedHelpper(root, height);
    }
};