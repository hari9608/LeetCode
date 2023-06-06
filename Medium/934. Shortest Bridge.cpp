/*
934. Shortest Bridge
Medium
4.8K
181
company
Google
company
Amazon
company
Microsoft

You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.

 

Example 1:

Input: grid = [[0,1],[1,0]]
Output: 1

Example 2:

Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2

Example 3:

Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1

 

Constraints:

    n == grid.length == grid[i].length
    2 <= n <= 100
    grid[i][j] is either 0 or 1.
    There are exactly two islands in grid.

Accepted
170.5K
Submissions
295.1K
Acceptance Rate
57.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (37)
Related Topics
Array
Depth-First Search
Breadth-First Search
Matrix
*/
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int grid_len = grid.size();
        int shortest_bridge = 0;
        int first_x = -1;
        int first_y = -1;

        for (int i = 0; i < grid_len; i++) 
            for (int j = 0; j < grid_len; j++) 
                if (grid[i][j] == 1) 
                {
                    first_x = i;
                    first_y = j;
                    break;
                }

        queue<pair<int, int>> bfs;
        queue<pair<int, int>> first_island;
        vector<int> x_axis{0, 1, 0, -1};
        vector<int> y_axis{-1, 0, 1, 0};

        first_island.push({first_x, first_y});
        bfs.push({first_x, first_y});

        grid[first_x][first_y] = 2;

        while(!bfs.empty())
        {
            int x = bfs.front().first;
            int y = bfs.front().second;
            bfs.pop();

            for(int i = 0; i < 4; i++)
            {
                int row = x + x_axis[i];
                int col = y + y_axis[i];
                
                if(row >= 0 && col >= 0 && row < grid_len && col < grid_len && grid[row][col] == 1)
                {
                    first_island.push({row, col});
                    bfs.push({row, col});
                    grid[row][col] = 2;
                }
            }
        }

        while(!first_island.empty())
        {
            int first_island_size = first_island.size();

            for(int i = 0; i < first_island_size; i++)
            {
                int x = first_island.front().first;
                int y = first_island.front().second;
                first_island.pop();

                for(int i = 0; i < 4; i++)
                {
                    int row = x + x_axis[i];
                    int col = y + y_axis[i];
                    
                    if(row >= 0 && col >= 0 && row < grid_len && col < grid_len)
                    {
                        if(grid[row][col] == 1)
                            return shortest_bridge;
                        else if(grid[row][col] == 0)
                        {
                            first_island.push({row, col});
                            grid[row][col] = -1;
                        }
                    }
                }
            }
            shortest_bridge++;
        }

        return shortest_bridge;
    }
};