/*
1514. Path with Maximum Probability
Medium
2.8K
62
company
Google

You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

 

Example 1:

Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.

Example 2:

Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000

Example 3:

Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.

 

Constraints:

    2 <= n <= 10^4
    0 <= start, end < n
    start != end
    0 <= a, b < n
    a != b
    0 <= succProb.length == edges.length <= 2*10^4
    0 <= succProb[i] <= 1
    There is at most one edge between every two nodes.

Accepted
111.3K
Submissions
204.1K
Acceptance Rate
54.6%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (33)
Similar Questions
Number of Ways to Arrive at Destination
Medium
Related Topics
Array
Graph
Heap (Priority Queue)
Shortest Path
*/

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        map<int, vector<pair<int, int>>> connections;

        for(int ind = 0; ind < edges.size(); ind++)
        {
            int from = edges[ind][0];
            int to = edges[ind][1];

            connections[from].push_back({to, ind});
            connections[to].push_back({from, ind});
        }

        vector<double> probability(n, 0.0);
        probability[start] = 1.0;

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});

        while(!pq.empty())
        {
            double prob = pq.top().first;
            int from = pq.top().second;
            
            pq.pop();

            if(from == end)
                return prob;

            if(probability[from] > prob)
                continue;

            for(auto connect : connections[from])
            {
                double to = connect.first;
                int edge_ind = connect.second;
                double next_prob = prob * succProb[edge_ind];

                if(next_prob > probability[to])
                {
                    probability[to] = next_prob;
                    pq.push({next_prob, to});
                }
            }
        }

        return 0.0;
    }
};