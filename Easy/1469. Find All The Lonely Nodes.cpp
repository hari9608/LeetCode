/*
1469. Find All The Lonely Nodes
Easy
459
9
company
Microsoft

In a binary tree, a lonely node is a node that is the only child of its parent node. The root of the tree is not lonely because it does not have a parent node.

Given the root of a binary tree, return an array containing the values of all lonely nodes in the tree. Return the list in any order.

 

Example 1:

Input: root = [1,2,3,null,4]
Output: [4]
Explanation: Light blue node is the only lonely node.
Node 1 is the root and is not lonely.
Nodes 2 and 3 have the same parent and are not lonely.

Example 2:

Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2]
Output: [6,2]
Explanation: Light blue nodes are lonely nodes.
Please remember that order doesn't matter, [2,6] is also an acceptable answer.

Example 3:


Input: root = [11,99,88,77,null,null,66,55,null,null,44,33,null,null,22]
Output: [77,55,33,66,44,22]
Explanation: Nodes 99 and 88 share the same parent. Node 11 is the root.
All other nodes are lonely.

 

Constraints:

    The number of nodes in the tree is in the range [1, 1000].
    1 <= Node.val <= 106

Accepted
44.4K
Submissions
54K
Acceptance Rate
82.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (2)
Similar Questions
Binary Tree Tilt
Easy
Univalued Binary Tree
Easy
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
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> lonely_nodes;
        queue<TreeNode*> que;

        que.push(root);

        while(!que.empty())
        {
            int que_len = que.size();

            for(int ind = 0; ind < que_len; ind++)
            {
                TreeNode *tptr = que.front();
                que.pop();

                if(tptr->left && !tptr->right)
                    lonely_nodes.push_back(tptr->left->val);

                if(!tptr->left && tptr->right)
                    lonely_nodes.push_back(tptr->right->val);

                if(tptr->left)
                    que.push(tptr->left);
                    
                if(tptr->right)
                    que.push(tptr->right);
            }
        }

        return lonely_nodes;
    }
};