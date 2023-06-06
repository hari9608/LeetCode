/*
2316. Count Unreachable Pairs of Nodes in an Undirected Graph
Medium
1.8K
40
company
Amazon

You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from each other.

 

Example 1:

Input: n = 3, edges = [[0,1],[0,2],[1,2]]
Output: 0
Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.

Example 2:

Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
Output: 14
Explanation: There are 14 pairs of nodes that are unreachable from each other:
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
Therefore, we return 14.

 

Constraints:

    1 <= n <= 105
    0 <= edges.length <= 2 * 105
    edges[i].length == 2
    0 <= ai, bi < n
    ai != bi
    There are no repeated edges.

Accepted
73K
Submissions
144.5K
Acceptance Rate
50.5%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (40)
Similar Questions
Number of Islands
Medium
Related Topics
Depth-First Search
Breadth-First Search
Union Find
Graph
*/
class Solution {
public:
    int findNeighbor(int node, vector<vector<int>> &graph, vector<bool> &visited)
    {
        visited[node] = true;
        int count = 1;
        queue<int> q;
        q.push(node);

        while(!q.empty())
        {
            node = q.front();
            q.pop();
            
            for(auto path : graph[node])
                if(!visited[path])
                {
                    visited[path] = true;
                    q.push(path);
                    count++;
                }
        }

        return count;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        long long count_pairs = 0;
        long long edge_node_size  = 0;
        long long unjoined_node = n;
        vector<vector<int>> graph(n);
        vector<bool> visited(n);

        for(auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for(int i=0; i<n; i++)
            if(!visited[i])
            {
                edge_node_size = findNeighbor(i, graph, visited);
                count_pairs += edge_node_size * (unjoined_node - edge_node_size);
                unjoined_node -= edge_node_size;
            }

        return count_pairs;
    }
};