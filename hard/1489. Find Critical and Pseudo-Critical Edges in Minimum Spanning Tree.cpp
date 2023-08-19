/*
1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
Hard
1.3K
109
company
Amazon

Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.

Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.

Note that you can return the indices of the edges in any order.

 

Example 1:

Input: n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
Output: [[0,1],[2,3,4,5]]
Explanation: The figure above describes the graph.
The following figure shows all the possible MSTs:

Notice that the two edges 0 and 1 appear in all MSTs, therefore they are critical edges, so we return them in the first list of the output.
The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they are considered pseudo-critical edges. We add them to the second list of the output.

Example 2:

Input: n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
Output: [[],[0,1,2,3]]
Explanation: We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.

 

Constraints:

    2 <= n <= 100
    1 <= edges.length <= min(200, n * (n - 1) / 2)
    edges[i].length == 3
    0 <= ai < bi < n
    1 <= weighti <= 1000
    All pairs (ai, bi) are distinct.

Accepted
27.4K
Submissions
42.8K
Acceptance Rate
64.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (68)
Related Topics
Union Find
Graph
Sorting
Minimum Spanning Tree
Strongly Connected Component
*/
class Solution {
public:
    class UnionFind {
    public:
        vector<int> parent;
        vector<int> size;
        int maxSize;

        UnionFind(int n) {
            parent.resize(n);
            size.resize(n, 1);
            maxSize = 1;
            for (int i = 0; i < n; i++) 
                parent[i] = i;
        }

        int find(int x) {
            if (x != parent[x]) 
                parent[x] = find(parent[x]);

            return parent[x];
        }

        bool unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) 
            {
                if (size[rootX] < size[rootY]) 
                    swap(rootX, rootY);
                
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
                maxSize = max(maxSize, size[rootX]);

                return true;
            }

            return false;
        }
    };

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        auto newEdges = edges;
        int m = newEdges.size();

        for (int i = 0; i < m; i++) 
            newEdges[i].push_back(i);

        sort(newEdges.begin(), newEdges.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });

        UnionFind ufStd(n);
        int stdWeight = 0;
        for (const auto& edge : newEdges) 
            if (ufStd.unite(edge[0], edge[1])) 
                stdWeight += edge[2];
            
        vector<vector<int>> results(2);

        for (int i = 0; i < m; i++) 
        {
            UnionFind ufIgnore(n);
            int ignoreWeight = 0;
            for (int j = 0; j < m; j++) 
                if (i != j && ufIgnore.unite(newEdges[j][0], newEdges[j][1])) 
                    ignoreWeight += newEdges[j][2];
            
            if (ufIgnore.maxSize < n || ignoreWeight > stdWeight) 
                results[0].push_back(newEdges[i][3]);
            else 
            {
                UnionFind ufForce(n);
                ufForce.unite(newEdges[i][0], newEdges[i][1]);
                int forceWeight = newEdges[i][2];
                for (int j = 0; j < m; j++) 
                    if (i != j && ufForce.unite(newEdges[j][0], newEdges[j][1])) 
                        forceWeight += newEdges[j][2];

                if (forceWeight == stdWeight) 
                    results[1].push_back(newEdges[i][3]);
            }
        }

        return results;
    }
};