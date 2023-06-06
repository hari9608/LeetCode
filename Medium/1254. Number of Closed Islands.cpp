/*
1254. Number of Closed Islands
Medium
4.2K
138
company
Google
company
Amazon
company
Adobe

Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

 

Example 1:

Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).

Example 2:

Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1

Example 3:

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2

 

Constraints:

    1 <= grid.length, grid[0].length <= 100
    0 <= grid[i][j] <=1

Accepted
191.4K
Submissions
286.1K
Acceptance Rate
66.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (54)
Related Topics
Array
Depth-First Search
Breadth-First Search
Union Find
Matrix
*/
class Solution {
public:
    bool bfs(int r, int c, int grid_row, int grid_col, vector<vector<int>>& grid, vector<vector<bool>>& visited) 
    {
        queue<pair<int, int>> que;
        que.push({r, c});
        visited[r][c] = true;
        bool is_closed = true;

        vector<int> x_axis{0, 1, 0, -1};
        vector<int> y_axis{-1, 0, 1, 0};

        while(!que.empty())
        {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();

            for(int i = 0; i < 4; i++)
            {
                int row = x + x_axis[i];
                int col = y + y_axis[i];
                
                if(row < 0 || col < 0 || row >= grid_row || col >= grid_col)
                    is_closed = false;
                else if (!grid[row][col] && !visited[row][col])
                {
                    que.push({row, col});
                    visited[row][col] = true;
                }
            }
        }

        return is_closed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int closed_island = 0;
        int grid_row = grid.size();
        int grid_col = grid[0].size();
        vector<vector<bool>> visited(grid_row, vector<bool>(grid_col));

        for(int r = 0; r < grid_row; r++)
            for(int c = 0; c < grid_col; c++)
                if(!grid[r][c] && !visited[r][c] && bfs(r, c, grid_row, grid_col, grid, visited))
                    closed_island++;

        return  closed_island;
    }
};