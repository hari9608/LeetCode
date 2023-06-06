/*
199. Binary Tree Right Side View
Medium
10.1K
613
company
Facebook
company
Amazon
company
Bloomberg

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:

Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Example 2:

Input: root = [1,null,3]
Output: [1,3]

Example 3:

Input: root = []
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100

Accepted
957.6K
Submissions
1.5M
Acceptance Rate
61.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (31)
Similar Questions
Populating Next Right Pointers in Each Node
Medium
Boundary of Binary Tree
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> right_side_view;
        queue<TreeNode*> levels;

        if(root)    
            levels.push(root);

        while(!levels.empty())
        {
            int level;
            int lev_len = levels.size();

            for(int i = 0; i < lev_len; i++)
            {
                TreeNode* temp = levels.front();    
                    levels.pop();

                if(temp->left)      
                    levels.push(temp->left);

                if(temp->right)     
                    levels.push(temp->right);

                level = temp->val;
            }

            right_side_view.push_back(level);
        }

        return right_side_view;
    }
};