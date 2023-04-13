/*
1857. Largest Color Value in a Directed Graph
Hard
1.8K
60
company
TikTok
company
Apple
company
Accolite

There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.

You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.

A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.

Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.

 

Example 1:

Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
Output: 3
Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).

Example 2:

Input: colors = "a", edges = [[0,0]]
Output: -1
Explanation: There is a cycle from 0 to 0.

 

Constraints:

    n == colors.length
    m == edges.length
    1 <= n <= 105
    0 <= m <= 105
    colors consists of lowercase English letters.
    0 <= aj, bj < n

Accepted
52.9K
Submissions
101K
Acceptance Rate
52.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (28)
Related Topics
Hash Table
Dynamic Programming
Graph
Topological Sort
Memoization
Counting
*/

class Solution {

public:

    int dfs(int node, string& colors, vector<vector<int>>& adj, vector<vector<int>>& count, vector<bool>& visit, vector<bool>& inStack) 

    {

        if (inStack[node])

            return INT_MAX;

        

        if (visit[node])

            return count[node][colors[node] - 'a'];

        

        visit[node] = true;

        inStack[node] = true;



        for (auto& neighbor : adj[node]) 

        {

            if (dfs(neighbor, colors, adj, count, visit, inStack) == INT_MAX) 

                return INT_MAX;

            

            for (int i = 0; i < 26; i++) 

                count[node][i] = max(count[node][i], count[neighbor][i]);

        }



        count[node][colors[node] - 'a']++;

        inStack[node] = false;



        return count[node][colors[node] - 'a'];

    }



    int largestPathValue(string colors, vector<vector<int>>& edges) {

        int n = colors.length();

        vector<vector<int>> adj(n);



        for (auto& edge : edges)

            adj[edge[0]].push_back(edge[1]);



        vector<vector<int>> count(n, vector<int>(26));

        vector<bool> visit(n), inStack(n);

        int answer = 0;

        

        for (int i = 0; i < n; i++)

            answer = max(answer, dfs(i, colors, adj, count, visit, inStack));



        return answer == INT_MAX ? -1 : answer;

    }

};