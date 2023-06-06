/*
2471. Minimum Number of Operations to Sort a Binary Tree by Level
Medium
496
12
company
Amazon

You are given the root of a binary tree with unique values.

In one operation, you can choose any two nodes at the same level and swap their values.

Return the minimum number of operations needed to make the values at each level sorted in a strictly increasing order.

The level of a node is the number of edges along the path between it and the root node.

 

Example 1:

Input: root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
Output: 3
Explanation:
- Swap 4 and 3. The 2nd level becomes [3,4].
- Swap 7 and 5. The 3rd level becomes [5,6,8,7].
- Swap 8 and 7. The 3rd level becomes [5,6,7,8].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.

Example 2:

Input: root = [1,3,2,7,6,5,4]
Output: 3
Explanation:
- Swap 3 and 2. The 2nd level becomes [2,3].
- Swap 7 and 4. The 3rd level becomes [4,6,5,7].
- Swap 6 and 5. The 3rd level becomes [4,5,6,7].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.

Example 3:

Input: root = [1,2,3,4,5,6]
Output: 0
Explanation: Each level is already sorted in increasing order so return 0.

 

Constraints:

    The number of nodes in the tree is in the range [1, 105].
    1 <= Node.val <= 105
    All the values of the tree are unique.

Accepted
16.6K
Submissions
26.8K
Acceptance Rate
62.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (3)
Similar Questions
Binary Tree Level Order Traversal
Medium
Longest Cycle in a Graph
Hard
Related Topics
Tree
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
    int minNnumberSwap(vector<int> &level)
    {
        int min_swap = 0;
        int level_len = level.size();
        vector<pair<int, int>> indexed;

        for(int i=0; i<level_len; i++)
            indexed.push_back({level[i], i});

        sort(indexed.begin(), indexed.end());

        for(int i=0; i<level_len; i++)
            if(i == indexed[i].second)  continue;
            else    
            {
                swap(indexed[i], indexed[indexed[i].second]);
                min_swap++;
                i--;
            }

        return min_swap;
    }

    int minimumOperations(TreeNode* root) {
        int minimum_operations = 0;
        queue<TreeNode*> levels;

        if(root)    levels.push(root);

        while(!levels.empty())
        {
            vector<int> level;
            int lev_len = levels.size();

            for(int i=0; i<lev_len; i++)
            {
                TreeNode* temp = levels.front();    levels.pop();
                if(temp->left)      levels.push(temp->left);
                if(temp->right)     levels.push(temp->right);
                level.push_back(temp->val);
            }
           minimum_operations += minNnumberSwap(level);
        }

        return minimum_operations;
    }
};