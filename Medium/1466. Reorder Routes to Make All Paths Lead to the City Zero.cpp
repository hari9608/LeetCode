/*
1466. Reorder Routes to Make All Paths Lead to the City Zero
Medium
3.4K
77
company
Amazon
company
DRW
company
American Express

There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.

 

Example 1:

Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

Example 2:

Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

Example 3:

Input: n = 3, connections = [[1,0],[2,0]]
Output: 0

 

Constraints:

    2 <= n <= 5 * 104
    connections.length == n - 1
    connections[i].length == 2
    0 <= ai, bi <= n - 1
    ai != bi

Accepted
127.3K
Submissions
191.3K
Acceptance Rate
66.6%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (38)
Related Topics
Depth-First Search
Breadth-First Search
Graph
*/
class Solution {
public:
    int min_reorder = 0;
    void findReorder(int node, int parent, vector<vector<pair<int, int>>>& connections_path)
    {
        for(auto path : connections_path[node])
        {
            int child = path.first;
            int c_path = path.second;
            if(child != parent)
            {
                min_reorder += path.second;
                findReorder(child, node, connections_path);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> connections_path(n);

        for(auto connect : connections)
        {
            connections_path[connect[0]].push_back({connect[1],1});
            connections_path[connect[1]].push_back({connect[0],0});
        }
        findReorder(0, -1, connections_path);

        return min_reorder;
    }
};