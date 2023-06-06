/*
399. Evaluate Division
Medium
8.2K
724
company
Uber
company
BlackRock
company
Amazon

You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]

Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]

Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]

 

Constraints:

    1 <= equations.length <= 20
    equations[i].length == 2
    1 <= Ai.length, Bi.length <= 5
    values.length == equations.length
    0.0 < values[i] <= 20.0
    1 <= queries.length <= 20
    queries[i].length == 2
    1 <= Cj.length, Dj.length <= 5
    Ai, Bi, Cj, Dj consist of lower case English letters and digits.

Accepted
376.1K
Submissions
613.4K
Acceptance Rate
61.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (82)
Similar Questions
Check for Contradictions in Equations
Hard
Related Topics
Array
Depth-First Search
Breadth-First Search
Union Find
Graph
Shortest Path
*/
class Solution {
public:
    void dfs(string start, string end, map<string,double>& mp, map<string,vector<string>>& graph, double& val, map<string,int>& visited, bool& found){
        visited[start] = 1;

        if(found == true)
            return ;

        for(auto child : graph[start])
        {
            if(visited[child] != 1)
            {
                val *= mp[start + "->" + child];

                if(end == child)
                {
                    found = true;
                    return ;
                }

                dfs(child, end, mp, graph, val, visited, found);

                if(found == true)
                    return ;
                else
                    val /= mp[start + "->" + child];
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> calc_equation;
        map<string, double> mapp;
        map<string, vector<string>> graph;

        for(int i = 0; i < equations.size(); i++)
        {
            string u = equations[i][0];
            string v = equations[i][1];

            mapp[u + "->" + v] = values[i];
            mapp[v + "->" + u] = 1 / values[i];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for(int i = 0; i < queries.size(); i++)
        {
            string start = queries[i][0];
            string end = queries[i][1];
        
            if(graph.find(start) == graph.end() || graph.find(end) == graph.end())
                calc_equation.push_back(-1);
            else
            {
                double val = 1;
                map<string, int> visited;
                bool found = false;

                if(start == end)
                    found = true;
                else
                    dfs(start, end, mapp, graph, val, visited, found);
    
                if(found == true)
                    calc_equation.push_back(val);
                else
                    calc_equation.push_back(-1);
            }
        }

        return calc_equation;
    }
};