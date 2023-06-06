/*
1020. Number of Enclaves
Medium
3.4K
65
company
Amazon
company
Google

You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:

Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

Example 2:

Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 500
    grid[i][j] is either 0 or 1.

Accepted
162.6K
Submissions
236.6K
Acceptance Rate
68.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (37)
Related Topics
Array
Depth-First Search
Breadth-First Search
Union Find
Matrix
*/
class Solution {
public:
    void bfs(int r, int c, int grid_row, int grid_col, vector<vector<int>>& grid, vector<vector<bool>>& visited) 
    {
        queue<pair<int, int>> que;
        que.push({r, c});
        visited[r][c] = true;

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
                    continue;
                else if (grid[row][col] && !visited[row][col])
                {
                    que.push({row, col});
                    visited[row][col] = true;
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int num_enclaves = 0;
        int grid_row = grid.size();
        int grid_col = grid[0].size();
        vector<vector<bool>> visited(grid_row, vector<bool>(grid_col));

        for(int r = 0; r < grid_row; r++)
        {
            if(grid[r][0] && !visited[r][0])
                bfs(r, 0, grid_row, grid_col, grid, visited);

            if(grid[r][grid_col - 1] && !visited[r][grid_col - 1])
                bfs(r, grid_col - 1, grid_row, grid_col, grid, visited);
        }
        
        for(int c = 0; c < grid_col; c++)
        {
            if(grid[0][c] && !visited[0][c])
                bfs(0, c, grid_row, grid_col, grid, visited);

            if(grid[grid_row - 1][c] && !visited[grid_row - 1][c])
                bfs(grid_row - 1, c, grid_row, grid_col, grid, visited);
        }

        for(int r = 0; r < grid_row; r++)
            for(int c = 0; c < grid_col; c++)
                if(grid[r][c] && !visited[r][c])
                    num_enclaves++;

        return num_enclaves;
    }
};