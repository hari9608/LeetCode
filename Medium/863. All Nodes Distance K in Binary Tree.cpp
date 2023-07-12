/*
863. All Nodes Distance K in Binary Tree
Medium
9.5K
182
company
Amazon
company
Facebook
company
Google

Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

Example 2:

Input: root = [1], target = 1, k = 3
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [1, 500].
    0 <= Node.val <= 500
    All the values Node.val are unique.
    target is the value of one of the nodes in the tree.
    0 <= k <= 1000

Accepted
341.8K
Submissions
540.1K
Acceptance Rate
63.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (57)
Similar Questions
Amount of Time for Binary Tree to Be Infected
Medium
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<int, vector<int>> graph;

    void buildGraph(TreeNode *node, TreeNode *parent)
    {
        if(node && parent)
        {
            graph[node->val].push_back(parent->val);
            graph[parent->val].push_back(node->val);
        }

        if(node->left)
            buildGraph(node->left, node);

        if(node->right)
            buildGraph(node->right, node);
    }

    void dfs(int cur_val, int distance, int k, vector<int>& distance_k, set<int>& visited)
    {
        if(distance == k)
        {
            distance_k.push_back(cur_val);
            return ;
        }

        for(int neighbor : graph[cur_val])
            if(!visited.count(neighbor))
            {
                visited.insert(neighbor);
                dfs(neighbor, distance + 1, k, distance_k, visited);
            }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> distance_k;
        set<int> visited;

        visited.insert(target->val);
        
        buildGraph(root, NULL);

        dfs(target->val, 0, k, distance_k, visited);

        return distance_k;
    }
};

    // for(auto gr : graph)
    // {
    //     cout << gr.first << " ->  "; 
    //     for(int g : gr.second)
    //         cout << g << " ";
    //     cout << endl;
    // }