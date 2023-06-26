/*
113. Path Sum II
Medium
7.1K
141
company
Amazon
company
Bloomberg
company
Zillow

Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

 

Example 1:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

Example 2:

Input: root = [1,2,3], targetSum = 5
Output: []

Example 3:

Input: root = [1,2], targetSum = 0
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 5000].
    -1000 <= Node.val <= 1000
    -1000 <= targetSum <= 1000

Accepted
751.8K
Submissions
1.3M
Acceptance Rate
57.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (12)
Similar Questions
Path Sum
Easy
Binary Tree Paths
Easy
Path Sum III
Medium
Path Sum IV
Medium
Step-By-Step Directions From a Binary Tree Node to Another
Medium
Related Topics
Backtracking
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
    void findAllRootToLeaf(TreeNode* root, int targetSum, vector<vector<int>>& path_sum, vector<int>& path, int curr_sum) {
        path.push_back(root->val);
        curr_sum += root->val;

        if(!root->left && !root->right && targetSum == curr_sum)
        {
            path_sum.push_back(path);
            return ;
        }

        if(root->left)
        {
            findAllRootToLeaf(root->left, targetSum, path_sum, path, curr_sum);
            path.pop_back();
        }
        
        if(root->right)
        {
            findAllRootToLeaf(root->right, targetSum, path_sum, path, curr_sum);
            path.pop_back();
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> path_sum;
        vector<int> path;

        if(!root)
            return path_sum;

        findAllRootToLeaf(root, targetSum, path_sum, path, 0);

        return path_sum;
    }
};