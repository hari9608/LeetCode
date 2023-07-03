/*
250. Count Univalue Subtrees
Medium
1.1K
385
company
Google
company
Microsoft
company
Splunk

Given the root of a binary tree, return the number of uni-value
subtrees
.

A uni-value subtree means all nodes of the subtree have the same value.

 

Example 1:

Input: root = [5,1,5,5,5,null,5]
Output: 4

Example 2:

Input: root = []
Output: 0

Example 3:

Input: root = [5,5,5,5,5,null,5]
Output: 6

 

Constraints:

    The number of the node in the tree will be in the range [0, 1000].
    -1000 <= Node.val <= 1000

Accepted
141.7K
Submissions
253.8K
Acceptance Rate
55.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (13)
Similar Questions
Subtree of Another Tree
Easy
Longest Univalue Path
Medium
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
    bool dfs(TreeNode *root, int &count)
    {
        if(!root)
            return true;

        bool is_left = dfs(root->left, count);
        bool is_right = dfs(root->right, count);

        if(is_left && is_right)
        {
            if(root->left && root->val != root->left->val)
                return false;

            if(root->right && root->val != root->right->val)
                return false;

            count++;
            return true;
        }
        
        return false;
    }

    int countUnivalSubtrees(TreeNode* root) {
        int count_unival_subtrees = 0;
        dfs(root, count_unival_subtrees);

        return count_unival_subtrees;
    }
};