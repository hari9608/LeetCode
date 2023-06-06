/*
63. Unique Paths II
Medium
7K
441
Cruise Automation
company
Amazon
company
Google

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Example 2:

Input: obstacleGrid = [[0,1],[0,0]]
Output: 1

 

Constraints:

    m == obstacleGrid.length
    n == obstacleGrid[i].length
    1 <= m, n <= 100
    obstacleGrid[i][j] is 0 or 1.

Accepted
687.8K
Submissions
1.7M
Acceptance Rate
39.5%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (33)
Similar Questions
Unique Paths
Medium
Unique Paths III
Hard
Minimum Path Cost in a Grid
Medium
Paths in Matrix Whose Sum Is Divisible by K
Hard
Related Topics
Array
Dynamic Programming
Matrix
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int R = obstacleGrid.size();
        int C = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1)    return 0;

        obstacleGrid[0][0] = 1;

        for (int i = 1; i < R; i++)
            obstacleGrid[i][0] = (obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1) ? 1 : 0;
        for (int i = 1; i < C; i++)
            obstacleGrid[0][i] = (obstacleGrid[0][i] == 0 && obstacleGrid[0][i - 1] == 1) ? 1 : 0;

        for (int i = 1; i < R; i++) 
            for (int j = 1; j < C; j++) 
                if (obstacleGrid[i][j] == 0) 
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                else
                    obstacleGrid[i][j] = 0;

        return obstacleGrid[R - 1][C - 1];
    }
};