/*
988. Smallest String Starting From Leaf
Medium
1.5K
199
company
Bloomberg
company
Apple
company
Google

You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

As a reminder, any shorter prefix of a string is lexicographically smaller.

    For example, "ab" is lexicographically smaller than "aba".

A leaf of a node is a node that has no children.

 

Example 1:

Input: root = [0,1,2,3,4,3,4]
Output: "dba"

Example 2:

Input: root = [25,1,3,1,3,0,2]
Output: "adz"

Example 3:

Input: root = [2,2,1,null,1,0,null,0]
Output: "abc"

 

Constraints:

    The number of nodes in the tree is in the range [1, 8500].
    0 <= Node.val <= 25

Accepted
65.7K
Submissions
130.8K
Acceptance Rate
50.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (6)
Similar Questions
Sum Root to Leaf Numbers
Medium
Binary Tree Paths
Easy
Related Topics
String
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
    void findSmallest(string &smallest_from_leaf, string current, TreeNode* root)
    {
        if(!root) return;

        current = (char)(root->val + 'a') + current;
        
        if((smallest_from_leaf == "" || current < smallest_from_leaf) && !root->left && !root->right)
            smallest_from_leaf = current;
            
        findSmallest(smallest_from_leaf, current, root->left);
        findSmallest(smallest_from_leaf, current, root->right);
    }

    string smallestFromLeaf(TreeNode* root) {
        string smallest_from_leaf = "";
        string current = "";

        findSmallest(smallest_from_leaf, current, root);

        return smallest_from_leaf;
    }
};