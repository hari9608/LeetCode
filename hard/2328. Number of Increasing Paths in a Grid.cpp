/*
2328. Number of Increasing Paths in a Grid
Hard
1.7K
39
company
Adobe

You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions.

Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell. Since the answer may be very large, return it modulo 109 + 7.

Two paths are considered different if they do not have exactly the same sequence of visited cells.

 

Example 1:

Input: grid = [[1,1],[3,4]]
Output: 8
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [1], [3], [4].
- Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
- Paths with length 3: [1 -> 3 -> 4].
The total number of paths is 4 + 3 + 1 = 8.

Example 2:

Input: grid = [[1],[2]]
Output: 3
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [2].
- Paths with length 2: [1 -> 2].
The total number of paths is 2 + 1 = 3.

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 1000
    1 <= m * n <= 105
    1 <= grid[i][j] <= 105

Accepted
56K
Submissions
92.9K
Acceptance Rate
60.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (52)
Similar Questions
Longest Increasing Path in a Matrix
Hard
All Paths From Source to Target
Medium
Maximum Strictly Increasing Cells in a Matrix
Hard
Related Topics
Array
Dynamic Programming
Depth-First Search
Breadth-First Search
Graph
Topological Sort
Memoization
Matrix
*/
class Solution {
public:    
    int mod = 1e9 + 7;
    
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& dp, int row, int col, int m, int n) {
        if (dp[row][col] == -1)
        { 
            int rows[4] = {-1, 0, 1, 0};
            int cols[4] = {0, 1, 0, -1};
            long long curr_path_count = 1;

            for (int i = 0; i < 4; i++) 
            {
                int curr_row = row + rows[i];
                int curr_col = col + cols[i];
                
                if (curr_row >= 0 && curr_row < m && curr_col >= 0 && curr_col < n && grid[row][col] < grid[curr_row][curr_col]) 
                    curr_path_count += dfs(grid, dp, curr_row, curr_col, m, n);
            }
            
            return dp[row][col] = curr_path_count % mod;
        }

        return dp[row][col];
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long path_count = 0;
        
        vector<vector<int>> dp(m, vector<int>(n, -1));        
        
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                path_count += dfs(grid, dp, i, j, m, n);

        return path_count % mod;
    }
};