/*
257. Binary Tree Paths
Easy
5.8K
247
company
Amazon
company
Bloomberg
company
Capital One

Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

 

Example 1:

Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

Example 2:

Input: root = [1]
Output: ["1"]

 

Constraints:

    The number of nodes in the tree is in the range [1, 100].
    -100 <= Node.val <= 100

Accepted
621.9K
Submissions
1M
Acceptance Rate
61.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (11)
Similar Questions
Path Sum II
Medium
Smallest String Starting From Leaf
Medium
Step-By-Step Directions From a Binary Tree Node to Another
Medium
Related Topics
String
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
        
    void build_binary_paths(TreeNode* root, string path, vector<string> &binary_tree_paths){
        if(!root)   return;
        path += to_string(root->val);

        if(!root->left && !root->right)     binary_tree_paths.push_back(path);
        else
        {
            path += "->";
            build_binary_paths(root->left, path, binary_tree_paths);
            build_binary_paths(root->right, path, binary_tree_paths);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> binary_tree_paths;

        build_binary_paths(root, "", binary_tree_paths);

        return binary_tree_paths;
        }
};