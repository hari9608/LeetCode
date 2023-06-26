/*
797. All Paths From Source to Target
Medium
6.6K
136
company
Bloomberg
company
Google
company
Amazon

Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

 

Example 1:

Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

Example 2:

Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]

 

Constraints:

    n == graph.length
    2 <= n <= 15
    0 <= graph[i][j] < n
    graph[i][j] != i (i.e., there will be no self-loops).
    All the elements of graph[i] are unique.
    The input graph is guaranteed to be a DAG.

Accepted
444.2K
Submissions
539.6K
Acceptance Rate
82.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (36)
Similar Questions
Number of Ways to Arrive at Destination
Medium
Number of Increasing Paths in a Grid
Hard
Related Topics
Backtracking
Depth-First Search
Breadth-First Search
Graph
*/
class Solution {
public:
    void backtrack(vector<vector<int>>& graph, int curr_node, vector<vector<int>>& all_possible_paths, vector<int> possible_paths, int n) {
        if(curr_node == n)
        {
            all_possible_paths.push_back(possible_paths);
            return ;
        }

        for(auto next : graph[curr_node])
        {
            possible_paths.push_back(next);
            backtrack(graph, next, all_possible_paths, possible_paths, n);
            possible_paths.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size() - 1;
        vector<vector<int>> all_possible_paths;
        vector<int> possible_paths{0};

        backtrack(graph, 0, all_possible_paths, possible_paths, n);
        
        return all_possible_paths;
    }
};