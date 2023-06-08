/*
144. Binary Tree Preorder Traversal
Easy
6.9K
179
company
Google
company
Apple
company
Microsoft

Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]
Output: [1,2,3]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [1]
Output: [1]

 

Constraints:

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100

 

Follow up: Recursive solution is trivial, could you do it iteratively?
Accepted
1.3M
Submissions
2M
Acceptance Rate
67.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (51)
Similar Questions
Binary Tree Inorder Traversal
Easy
Verify Preorder Sequence in Binary Search Tree
Medium
N-ary Tree Preorder Traversal
Easy
Kth Largest Sum in a Binary Tree
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder_traversal;
        stack<TreeNode*> pre_stack;
        pre_stack.push(root);
        
        while (!pre_stack.empty()) 
        {
            TreeNode* currNode = pre_stack.top();
            pre_stack.pop();

            if (currNode) 
            {
                preorder_traversal.push_back(currNode -> val);
                
                pre_stack.push(currNode -> right);
                pre_stack.push(currNode -> left);
            }
        }
        
        return preorder_traversal;
    }
};