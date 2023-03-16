/*
429. N-ary Tree Level Order Traversal
Medium
3.3K
127
company
Amazon
company
Adobe
company
Microsoft

Given an n-ary tree, return the level order traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

 

Example 1:

Input: root = [1,null,3,2,4,null,5,6]
Output: [[1],[3,2,4],[5,6]]

Example 2:

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]

 

Constraints:

    The height of the n-ary tree is less than or equal to 1000
    The total number of nodes is between [0, 104]

Accepted
274.1K
Submissions
387.8K
Acceptance Rate
70.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (3)
Similar Questions
Binary Tree Level Order Traversal
Medium
N-ary Tree Preorder Traversal
Easy
N-ary Tree Postorder Traversal
Easy
The Time When the Network Becomes Idle
Medium
Related Topics
Tree
Breadth-First Search

*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> level_order;
        queue<Node*> levels;
        if(root)    levels.push(root);

        while(!levels.empty())
        {
            vector<int> level;
            int lev_len = levels.size();
            for(int i=0; i<lev_len; i++)
            {
                Node* temp = levels.front();        levels.pop();
                for(auto child : temp->children)    
                    levels.push(child);
                    
                level.push_back(temp->val);
            }
            level_order.push_back(level);
        }

        return level_order;
    }
};