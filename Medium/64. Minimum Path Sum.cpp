/*
64. Minimum Path Sum
Medium
10.7K
139
company
Goldman Sachs
company
Google
company
Amazon

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 200
    0 <= grid[i][j] <= 100

Accepted
925.6K
Submissions
1.5M
Acceptance Rate
62.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (53)
Similar Questions
Unique Paths
Medium
Dungeon Game
Hard
Cherry Pickup
Hard
Minimum Path Cost in a Grid
Medium
Maximum Number of Points with Cost
Medium
Minimum Cost Homecoming of a Robot in a Grid
Medium
Paths in Matrix Whose Sum Is Divisible by K
Hard
Check if There is a Path With Equal Number of 0's And 1's
Medium
Related Topics
Array
Dynamic Programming
Matrix
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row_size = grid.size() ;
        int col_size = grid[0].size();

        for(int i = row_size - 1; i>=0; i--)
            for(int j = col_size - 1; j>=0; j--)
                if(i != row_size - 1 && j != col_size - 1)      grid[i][j] = grid[i][j] + min(grid[i+1][j], grid[i][j+1]);
                else if(i != row_size - 1 && j == col_size - 1)     grid[i][j] = grid[i][j] + grid[i+1][j];
                else if(i == row_size - 1 && j != col_size - 1)     grid[i][j] = grid[i][j] + grid[i][j+1];

        return grid[0][0];
    }
};
