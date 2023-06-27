/*
1214. Two Sum BSTs
Medium
513
44
company
Amazon

Given the roots of two binary search trees, root1 and root2, return true if and only if there is a node in the first tree and a node in the second tree whose values sum up to a given integer target.

 

Example 1:

Input: root1 = [2,1,4], root2 = [1,0,3], target = 5
Output: true
Explanation: 2 and 3 sum up to 5.

Example 2:

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2], target = 18
Output: false

 

Constraints:

    The number of nodes in each tree is in the range [1, 5000].
    -109 <= Node.val, target <= 109

Accepted
42.9K
Submissions
64.2K
Acceptance Rate
66.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (2)
Similar Questions
Two Sum IV - Input is a BST
Easy
Related Topics
Two Pointers
Binary Search
Stack
Tree
Depth-First Search
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
    void inOrder(TreeNode *root, vector<int>& tree)
    {
        if(root)
        {
            inOrder(root->left, tree);
            tree.push_back(root->val);
            inOrder(root->right, tree);
        }
    }

    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<int> tree1; 
        vector<int> tree2;

        inOrder(root1, tree1);
        inOrder(root2, tree2);

        int ind1 = tree1.size() - 1;
        int ind2 = 0;

        while(ind1 >= 0 && ind2 < tree2.size())
        {
            if(tree1[ind1] + tree2[ind2] == target)
                return true;

            if(tree1[ind1] + tree2[ind2] > target)
                ind1--;
            else
                ind2++;            
        }

        return false;
    }
};