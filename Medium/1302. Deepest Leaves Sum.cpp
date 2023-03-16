/*
1302. Deepest Leaves Sum
Medium
4.1K
107
company
Google
company
Amazon
company
Microsoft
Given the root of a binary tree, return the sum of values of its deepest leaves.

 

Example 1:

Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15

Example 2:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19

 

Constraints:

    The number of nodes in the tree is in the range [1, 104].
    1 <= Node.val <= 100

Accepted
268K
Submissions
309.2K
Acceptance Rate
86.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (5)
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
    int deepestLeavesSum(TreeNode* root) {
        int deepest_leaves_sum = 0;
        queue<TreeNode *> levels;
        levels.push(root);

        while(!levels.empty())
        {
            int level_sum = 0;
            int lev_len = levels.size();
            for(int i=0; i<lev_len; i++)
            {
                TreeNode *temp = levels.front();    levels.pop();
                if(temp->left)      levels.push(temp->left);
                if(temp->right)     levels.push(temp->right);
                level_sum += temp->val;
            }
            deepest_leaves_sum = level_sum; 
        }

        return deepest_leaves_sum;
    }
};
