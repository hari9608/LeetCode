/*
637. Average of Levels in Binary Tree
Easy
4.7K
291
company
Amazon
company
Facebook
company
Microsoft
Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].

Example 2:

Input: root = [3,9,20,15,7]
Output: [3.00000,14.50000,11.00000]

 

Constraints:

    The number of nodes in the tree is in the range [1, 104].
    -231 <= Node.val <= 231 - 1

Accepted
395.3K
Submissions
550.8K
Acceptance Rate
71.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (7)
Similar Questions
Binary Tree Level Order Traversal
Medium
Binary Tree Level Order Traversal II
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> level_order;
        queue<TreeNode*> levels;
        if(root)    levels.push(root);

        while(!levels.empty())
        {
            double level_sum = 0.0;
            int lev_len = levels.size();
            for(int i=0; i<lev_len; i++)
            {
                TreeNode* temp = levels.front();    levels.pop();
                if(temp->left)      levels.push(temp->left);
                if(temp->right)     levels.push(temp->right);
                level_sum += temp->val;
            }
            level_order.push_back(level_sum / lev_len);
        }

        return level_order;
    }
};