/*
802. Find Eventual Safe States
Medium
4.6K
398
company
Amazon
company
Bloomberg
company
Mindtickle

There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

 

Example 1:
Illustration of graph

Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.

Example 2:

Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
Explanation:
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.

 

Constraints:

    n == graph.length
    1 <= n <= 104
    0 <= graph[i].length <= n
    0 <= graph[i][j] <= n - 1
    graph[i] is sorted in a strictly increasing order.
    The graph may contain self-loops.
    The number of edges in the graph will be in the range [1, 4 * 104].

Accepted
165.8K
Submissions
277.2K
Acceptance Rate
59.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (43)
Similar Questions
Build a Matrix With Conditions
Hard
Related Topics
Depth-First Search
Breadth-First Search
Graph
Topological Sort
*/
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> que;
        vector<bool> visited(n);
        vector<int> node_indeg(n, 0);
        vector<vector<int>> adj_node(n);
        vector<int> eventual_safe_nodes;
        
        for(int ind = 0; ind < n; ind++)
            for(int node : graph[ind])
            {
                adj_node[node].push_back(ind);
                node_indeg[ind]++;
            }

        for(int ind = 0; ind < n; ind++)
            if(!node_indeg[ind])
                que.push(ind);

        while(!que.empty())
        {
            int node = que.front();
            que.pop();

            visited[node] = true;

            for(int neighbor : adj_node[node])
            {
                node_indeg[neighbor]--;

                if(!node_indeg[neighbor])
                    que.push(neighbor);
            }
        }

        for(int ind = 0; ind < n; ind++)
            if(visited[ind])
                eventual_safe_nodes.push_back(ind);

        return eventual_safe_nodes;
    }
};