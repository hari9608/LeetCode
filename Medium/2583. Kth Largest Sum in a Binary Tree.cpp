/*
2583. Kth Largest Sum in a Binary Tree
Medium
362
8
company
Amazon

You are given the root of a binary tree and a positive integer k.

The level sum in the tree is the sum of the values of the nodes that are on the same level.

Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.

Note that two nodes are on the same level if they have the same distance from the root.

 

Example 1:

Input: root = [5,8,9,2,1,3,7,4,6], k = 2
Output: 13
Explanation: The level sums are the following:
- Level 1: 5.
- Level 2: 8 + 9 = 17.
- Level 3: 2 + 1 + 3 + 7 = 13.
- Level 4: 4 + 6 = 10.
The 2nd largest level sum is 13.

Example 2:

Input: root = [1,2,null,3], k = 1
Output: 3
Explanation: The largest level sum is 3.

 

Constraints:

    The number of nodes in the tree is n.
    2 <= n <= 105
    1 <= Node.val <= 106
    1 <= k <= n

Accepted
23.7K
Submissions
50.5K
Acceptance Rate
47.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (10)
Similar Questions
Binary Tree Preorder Traversal
Easy
Maximum Level Sum of a Binary Tree
Medium
Related Topics
Binary Search
Tree
Breadth-First Search
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long, vector<long>, greater<long>> k_large;
        queue<TreeNode*> queue_l;
        queue_l.push(root);

        int max_level = 0;
        int max_sum = INT_MIN;

        while(!queue_l.empty())
        {
            long long curr_level_sum = 0;
            int queue_len = queue_l.size();

            for(int i = 0; i < queue_len; i++)
            {
                TreeNode *curr_node = queue_l.front();
                queue_l.pop();
                
                curr_level_sum += curr_node->val;

                if(curr_node->left)     queue_l.push(curr_node->left);
                if(curr_node->right)    queue_l.push(curr_node->right);
            }

            k_large.push(curr_level_sum);

            if(k_large.size() > k)      k_large.pop();
        }

        return k_large.size() == k ? k_large.top() : -1;
    }
};