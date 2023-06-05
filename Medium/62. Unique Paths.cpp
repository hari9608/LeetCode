/*
62. Unique Paths
Medium
13.5K
380
company
Bloomberg
company
TikTok
company
Amazon

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:

Input: m = 3, n = 7
Output: 28

Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

 

Constraints:

    1 <= m, n <= 100

Accepted
1.3M
Submissions
2.2M
Acceptance Rate
62.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (55)
Similar Questions
Unique Paths II
Medium
Minimum Path Sum
Medium
Dungeon Game
Hard
Minimum Path Cost in a Grid
Medium
Minimum Cost Homecoming of a Robot in a Grid
Medium
Number of Ways to Reach a Position After Exactly k Steps
Medium
Paths in Matrix Whose Sum Is Divisible by K
Hard
Related Topics
Math
Dynamic Programming
Combinatorics
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
      vector<vector<int>> dp(m, vector<int>(n, 1));

      for(int col = 1; col < m; ++col)
        for(int row = 1; row < n; ++row)
          dp[col][row] = dp[col - 1][row] + dp[col][row - 1];
        
      return dp[m - 1][n - 1];
    }
};