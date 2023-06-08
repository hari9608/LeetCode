/*
226. Invert Binary Tree
Easy
12.3K
174
company
Google
company
Amazon
company
Apple

Given the root of a binary tree, invert the tree, and return its root.

 

Example 1:

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:

Input: root = [2,1,3]
Output: [2,3,1]

Example 3:

Input: root = []
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100

Accepted
1.6M
Submissions
2.1M
Acceptance Rate
75.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (86)
Similar Questions
Reverse Odd Levels of Binary Tree
Medium
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root)          return NULL;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty())
        {
            TreeNode *cur = que.front();
            que.pop();

            TreeNode *tem = cur->left;
            cur->left = cur->right;
            cur->right = tem;

            if(cur->left)       que.push(cur->left);
            if(cur->right)      que.push(cur->right);
        }

        return root;
    }
};