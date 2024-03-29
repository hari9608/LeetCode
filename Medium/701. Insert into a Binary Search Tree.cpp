/*
701. Insert into a Binary Search Tree
Medium
4.9K
160
company
LinkedIn
company
Amazon
company
Goldman Sachs

You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

 

Example 1:

Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
Explanation: Another accepted tree is:

Example 2:

Input: root = [40,20,60,10,30,50,70], val = 25
Output: [40,20,60,10,30,50,70,null,null,25]

Example 3:

Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
Output: [4,2,7,1,3,5]

 

Constraints:

    The number of nodes in the tree will be in the range [0, 104].
    -108 <= Node.val <= 108
    All the values Node.val are unique.
    -108 <= val <= 108
    It's guaranteed that val does not exist in the original BST.

Accepted
416.6K
Submissions
561.6K
Acceptance Rate
74.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (17)
Similar Questions
Search in a Binary Search Tree
Easy
Related Topics
Tree
Binary Search Tree
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = root;

        while(node)
        {
            if(val < node->val)
                if(!node->left)
                {
                    node->left = new TreeNode(val);
                    return root;
                }
                else
                    node = node->left;

            else
                if(!node->right)
                {
                    node->right = new TreeNode(val);
                    return root;
                }
                else 
                    node = node->right;
        }

        return new TreeNode(val);
    }
};