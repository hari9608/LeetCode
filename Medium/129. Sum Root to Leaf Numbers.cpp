/*
129. Sum Root to Leaf Numbers
Medium
6.5K
100
company
Facebook
company
Microsoft
company
Amazon

You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

    For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.

Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

 

Example 1:

Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

Example 2:

Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.

 

Constraints:

    The number of nodes in the tree is in the range [1, 1000].
    0 <= Node.val <= 9
    The depth of the tree will not exceed 10.

Accepted
598.9K
Submissions
982.8K
Acceptance Rate
60.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (38)
Similar Questions
Path Sum
Easy
Binary Tree Maximum Path Sum
Hard
Smallest String Starting From Leaf
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
    void leafSums(TreeNode* root, vector<int> &v, int rs){
        if(!root) return;
        if(!root->left && !root->right){
            v.push_back(rs*10+root->val);
            return;
        }
        leafSums(root->left, v, rs*10+root->val); 
        leafSums(root->right, v, rs*10+root->val); 
    }
    int sumNumbers(TreeNode* root) {
        vector<int> res;
        int sum = 0;
        if(!root) return sum;
        leafSums(root, res, 0);
        for(auto v:res) sum += v;
        return sum;
    }
};