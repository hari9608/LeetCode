/*
931. Minimum Falling Path Sum
Medium
4.8K
123
company
Amazon
company
Visa
company
Google

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:

Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.

Example 2:

Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.

 

Constraints:

    n == matrix.length == matrix[i].length
    1 <= n <= 100
    -100 <= matrix[i][j] <= 100

Accepted
250.2K
Submissions
362.1K
Acceptance Rate
69.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (35)
Similar Questions
Minimum Falling Path Sum II
Hard
Related Topics
Array
Dynamic Programming
Matrix
*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix.size() + 1, 0));
        int minFallingSum = INT_MAX;

        for (int row = matrix.size() - 1; row >= 0; row--) 
        {
            for (int col = 0; col < matrix.size(); col++) 
            {
                if (col == 0) 
                    dp[row][col] = min(dp[row + 1][col], dp[row + 1][col + 1]) + matrix[row][col];
                else if (col == matrix.size() - 1) 
                    dp[row][col] = min(dp[row + 1][col], dp[row + 1][col - 1]) + matrix[row][col];
                else
                    dp[row][col] = min(dp[row + 1][col], min(dp[row + 1][col + 1], dp[row + 1][col - 1])) + matrix[row][col];
            }
        }
                    
        for (int startCol = 0; startCol < matrix.size(); startCol++)
            minFallingSum = min(minFallingSum, dp[0][startCol]);
        
        return minFallingSum;
    }
};