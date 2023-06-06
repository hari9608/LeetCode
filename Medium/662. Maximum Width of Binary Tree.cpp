/*
662. Maximum Width of Binary Tree
Medium
7.6K
1K
company
Amazon
company
Bloomberg
company
Google

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

 

Example 1:

Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

Example 2:

Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

Example 3:

Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).

 

Constraints:

    The number of nodes in the tree is in the range [1, 3000].
    -100 <= Node.val <= 100

Accepted
301.4K
Submissions
705.7K
Acceptance Rate
42.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (59)
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
    int widthOfBinaryTree(TreeNode* root) {        
        if (!root)
            return 0;

        queue<pair<TreeNode*, int>> que;
        int width_of_binary_tree = 1;

        que.push({root, 0});

        while(!que.empty())
        {
            int start_value = que.front().second;
            int end_value = que.back().second;
            int level_size = que.size();
            
            width_of_binary_tree = max(width_of_binary_tree, end_value - start_value + 1);

            for(int i = 0; i < level_size; i++)
            {
                TreeNode* front_node = que.front().first;
                int front_level = que.front().second - start_value + 1;

                que.pop();

                if(front_node -> left)
                    que.push({front_node -> left, (long long)2 * front_level});

                if(front_node -> right)
                    que.push({front_node -> right, (long long)2 * front_level + 1});
            }
        }

        return width_of_binary_tree;
    }
};