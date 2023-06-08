/*
145. Binary Tree Postorder Traversal
Easy
6K
174
company
Yahoo
company
Facebook
company
Bloomberg

Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]
Output: [3,2,1]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [1]
Output: [1]

 

Constraints:

    The number of the nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100

 
Follow up: Recursive solution is trivial, could you do it iteratively?
Accepted
968.1K
Submissions
1.4M
Acceptance Rate
68.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (22)
Similar Questions
Binary Tree Inorder Traversal
Easy
N-ary Tree Postorder Traversal
Easy
Minimum Fuel Cost to Report to the Capital
Medium
Related Topics
Stack
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
    void traverse(TreeNode* root, vector<int>& ans)
    {
        if(root==NULL)      
            return;

        traverse(root->left, ans);
        traverse(root->right, ans);
        ans.push_back(root->val); 
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> inorder_traversal;
        traverse(root, inorder_traversal);

        return inorder_traversal;
    }
};