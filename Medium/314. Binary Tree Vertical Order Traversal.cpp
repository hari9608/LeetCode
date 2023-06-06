/*
314. Binary Tree Vertical Order Traversal
Medium
2.9K
293
company
Facebook
company
Bloomberg
company
Amazon

Given the root of a binary tree, return the vertical order traversal of its nodes' values. (i.e., from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]

Example 2:

Input: root = [3,9,8,4,0,1,7]
Output: [[4],[9],[3,0,1],[8],[7]]

Example 3:

Input: root = [3,9,8,4,0,1,7,null,null,null,2,5]
Output: [[4],[9,5],[3,0,1],[8,2],[7]]

 

Constraints:

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100

Accepted
320.8K
Submissions
612.7K
Acceptance Rate
52.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (8)
Similar Questions
Binary Tree Level Order Traversal
Medium
Related Topics
Hash Table
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
    void verticalTraversalWithLevel(TreeNode* root, int head_distance, int level, map<int, map<int, vector<int>>> &mapp){
        if(!root) 
            return ;
        
        mapp[head_distance][level].push_back(root->val);
        verticalTraversalWithLevel(root->left, head_distance-1, level+1, mapp);
        verticalTraversalWithLevel(root->right, head_distance+1, level+1, mapp);
    }

    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> vertical_order;
        if(!root) 
            return vertical_order;
        map<int, map<int, vector<int>>> mapp;
        verticalTraversalWithLevel(root, 0, 0, mapp);

        for(auto i: mapp)
        {
            vector<int> v_in;

            for(auto j: i.second)
                for(auto v:j.second) 
                    v_in.push_back(v);

            vertical_order.push_back(v_in);
        }

        return vertical_order;
    }
};