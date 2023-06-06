/*
1161. Maximum Level Sum of a Binary Tree
Medium
2K
71
company
Facebook
company
Microsoft
company
Google

Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

 

Example 1:

Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.

Example 2:

Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2

 

Constraints:

    The number of nodes in the tree is in the range [1, 104].
    -105 <= Node.val <= 105

Accepted
131.6K
Submissions
199.3K
Acceptance Rate
66.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (6)
Similar Questions
Kth Largest Sum in a Binary Tree
Medium
Cousins in Binary Tree II
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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> queue_l;
        queue_l.push(root);

        int level = 0;
        int max_level = 0;
        int max_sum = INT_MIN;

        while(!queue_l.empty())
        {
            level++;
            int curr_level_sum = 0;
            int queue_len = queue_l.size();

            for(int i = 0; i < queue_len; i++)
            {
                TreeNode *curr_node = queue_l.front();
                queue_l.pop();
                
                curr_level_sum += curr_node->val;

                if(curr_node->left)     queue_l.push(curr_node->left);
                if(curr_node->right)    queue_l.push(curr_node->right);
            }

            if(curr_level_sum > max_sum)
            {
                max_sum = curr_level_sum;
                max_level = level;
            }
        }

        return max_level;
    }
};/**
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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> queue_l;
        queue_l.push(root);

        int level = 0;
        int max_level = 0;
        int max_sum = INT_MIN;

        while(!queue_l.empty())
        {
            level++;
            int curr_level_sum = 0;
            int queue_len = queue_l.size();

            for(int i = 0; i < queue_len; i++)
            {
                TreeNode *curr_node = queue_l.front();
                queue_l.pop();
                
                curr_level_sum += curr_node->val;

                if(curr_node->left)     queue_l.push(curr_node->left);
                if(curr_node->right)    queue_l.push(curr_node->right);
            }

            if(curr_level_sum > max_sum)
            {
                max_sum = curr_level_sum;
                max_level = level;
            }
        }

        return max_level;
    }
};