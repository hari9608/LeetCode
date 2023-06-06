/*
1319. Number of Operations to Make Network Connected
Medium
4.4K
60
company
PayTM
company
Palantir Technologies
company
Amazon

There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

 

Example 1:

Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

Example 2:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2

Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.

 

Constraints:

    1 <= n <= 105
    1 <= connections.length <= min(n * (n - 1) / 2, 105)
    connections[i].length == 2
    0 <= ai, bi < n
    ai != bi
    There are no repeated connections.
    No two computers are connected by more than one cable.

Accepted
175K
Submissions
281.4K
Acceptance Rate
62.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (39)
Related Topics
Depth-First Search
Breadth-First Search
Union Find
Graph
*/
class Solution {
public:
    void find_neighbors(int node, vector<vector<int>> &connections_path, vector<bool>  &visited)
    {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto path : connections_path[node])
                if(!visited[path])
                {
                    visited[path] = true;
                    q.push(path);
                }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)    return -1;

        vector<vector<int>> connections_path(n);
        vector<bool>  visited(n);
        
        int make_connected = -1;

        for(auto connection : connections)
        {
            connections_path[connection[0]].push_back(connection[1]);
            connections_path[connection[1]].push_back(connection[0]);
        }
        
        for(int i=0; i<n; i++)
            if(!visited[i])
            {
                make_connected++;
                find_neighbors(i, connections_path, visited);
            }

        return make_connected;
    }
};