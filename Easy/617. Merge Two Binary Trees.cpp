/*
617. Merge Two Binary Trees
Easy
8.2K
279
company
Apple
company
Amazon
company
Facebook

You are given two binary trees root1 and root2.

Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

Return the merged tree.

Note: The merging process must start from the root nodes of both trees.

 

Example 1:

Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
Output: [3,4,5,5,4,null,7]

Example 2:

Input: root1 = [1], root2 = [1,2]
Output: [2,2]

 

Constraints:

    The number of nodes in both trees is in the range [0, 2000].
    -104 <= Node.val <= 104

Accepted
689.6K
Submissions
876.5K
Acceptance Rate
78.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (10)
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root2==NULL) return root1;
        if(root1==NULL) return root2;

        TreeNode* merge = root1;
        stack<TreeNode*> s1, s2;
        s1.push(root1), s2.push(root2);
        while(!s1.empty()){
            TreeNode* c1=s1.top();
            TreeNode* c2=s2.top();
            s1.pop();
            s2.pop();
            c1->val += c2->val;
            if(c1->right==NULL && c2->right!=NULL) c1->right=c2->right;
            else if(c1->right!=NULL && c2->right!=NULL) s1.push(c1->right), s2.push(c2->right); 
            if(c1->left==NULL && c2->left!=NULL) c1->left=c2->left;
            else if(c1->left!=NULL && c2->left!=NULL) s1.push(c1->left), s2.push(c2->left); 
            
        }
        return merge;
    }
};