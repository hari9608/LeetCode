/*
106. Construct Binary Tree from Inorder and Postorder Traversal
Medium
6.6K
97
company
Amazon
company
Google
Shopee

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:

Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]

 

Constraints:

    1 <= inorder.length <= 3000
    postorder.length == inorder.length
    -3000 <= inorder[i], postorder[i] <= 3000
    inorder and postorder consist of unique values.
    Each value of postorder also appears in inorder.
    inorder is guaranteed to be the inorder traversal of the tree.
    postorder is guaranteed to be the postorder traversal of the tree.

Accepted
499.1K
Submissions
840.9K
Acceptance Rate
59.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (27)
Similar Questions
Construct Binary Tree from Preorder and Inorder Traversal
Medium
Related Topics
Array
Hash Table
Divide and Conquer
Tree
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int tree_size = postorder.size() - 1;
            return buildPreOrder(tree_size, inorder, postorder, 0, inorder.size() - 1);
    }

    TreeNode* buildPreOrder(int &tree_size, vector<int> &inorder, vector<int> &postorder, int left, int right){
        if(left > right) return NULL;
        int ind = right;
        while(postorder[tree_size] != inorder[ind])     ind--;      tree_size--;

        TreeNode* root = new TreeNode(inorder[ind]);
        root->right = buildPreOrder(tree_size,inorder,postorder,ind+1,right);
        root->left = buildPreOrder(tree_size,inorder,postorder,left,ind-1);
        
        return root;
    }
};