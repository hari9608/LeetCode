/*
111. Minimum Depth of Binary Tree
Easy
5.8K
1.1K
company
Amazon
company
Facebook
company
Bloomberg

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 2

Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5

 

Constraints:

    The number of nodes in the tree is in the range [0, 105].
    -1000 <= Node.val <= 1000

Accepted
945.5K
Submissions
2.1M
Acceptance Rate
44.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (30)
Similar Questions
Binary Tree Level Order Traversal
Medium
Maximum Depth of Binary Tree
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
    int minimumDepth(TreeNode* root)
    {
        if(!root)                           
            return 0;
        if(!root->left && !root->right)     
            return 1;
        
        int min_depth = INT_MAX;

        if(root->left)  
            min_depth = min(minimumDepth(root->left), min_depth);

        if(root->right)
            min_depth = min(minimumDepth(root->right), min_depth);

        return min_depth + 1;
    }

    int minDepth(TreeNode* root) {
        return minimumDepth(root);
    }
};