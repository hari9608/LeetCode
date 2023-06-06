/*
547. Number of Provinces
Medium
8.3K
311
company
Amazon
company
Bloomberg
company
DoorDash

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:

Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3

 

Constraints:

    1 <= n <= 200
    n == isConnected.length
    n == isConnected[i].length
    isConnected[i][j] is 1 or 0.
    isConnected[i][i] == 1
    isConnected[i][j] == isConnected[j][i]

Accepted
681.6K
Submissions
1M
Acceptance Rate
65.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (49)
Similar Questions
Number of Connected Components in an Undirected Graph
Medium
Robot Return to Origin
Easy
Sentence Similarity
Easy
Sentence Similarity II
Medium
The Earliest Moment When Everyone Become Friends
Medium
Detonate the Maximum Bombs
Medium
Related Topics
Depth-First Search
Breadth-First Search
Union Find
Graph
*/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int circle_num = 0;
        int n_cities = isConnected.size();
        vector<int> visited(n_cities, 0);
        map<int, vector<int>> connected;

        for(int i = 0; i < n_cities; i++)
            for(int j = 0; j < n_cities; j++)
                if(isConnected[i][j])
                    connected[i].push_back(j);
                    
        for(int i = 0; i < n_cities; i++)
            if(!visited[i])
            {
                circle_num++;

                queue<int> to_visit;
                to_visit.push(i);

                while(!to_visit.empty())
                {
                    int visit = to_visit.front();
                    to_visit.pop();
                    
                    for(int con : connected[visit])
                        if(!visited[con])
                        {
                            visited[con] = 1;
                            to_visit.push(con);
                        }
                }
            }
        
        return circle_num;
    }
};
