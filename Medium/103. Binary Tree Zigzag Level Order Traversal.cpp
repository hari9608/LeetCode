/*
103. Binary Tree Zigzag Level Order Traversal
Medium
8.9K
238
company
Bloomberg
company
Amazon
company
Microsoft

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 2000].
    -100 <= Node.val <= 100

Accepted
934.8K
Submissions
1.6M
Acceptance Rate
56.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (49)
Similar Questions
Binary Tree Level Order Traversal
Medium
Related Topics
Tree
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> level_order;
        queue<TreeNode*> levels;
        if(root)    levels.push(root);
        int flag = 0;

        while(!levels.empty())
        {
            vector<int> level;
            int lev_len = levels.size();
            for(int i=0; i<lev_len; i++)
            {
                TreeNode* temp = levels.front();    levels.pop();
                if(temp->left)      levels.push(temp->left);
                if(temp->right)     levels.push(temp->right);
                level.push_back(temp->val);
            }

            if(flag)    reverse(level.begin(), level.end());
            flag = !flag;

            level_order.push_back(level);
        }

        return level_order;
    }
};