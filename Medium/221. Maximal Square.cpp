/*
221. Maximal Square
Medium
8.9K
190
company
Amazon
company
TikTok
company
Apple

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4

Example 2:

Input: matrix = [["0","1"],["1","0"]]
Output: 1

Example 3:

Input: matrix = [["0"]]
Output: 0

 

Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 300
    matrix[i][j] is '0' or '1'.

Accepted
585.8K
Submissions
1.3M
Acceptance Rate
45.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (16)
Similar Questions
Maximal Rectangle
Hard
Largest Plus Sign
Medium
Count Artifacts That Can Be Extracted
Medium
Stamping the Grid
Hard
Related Topics
Array
Dynamic Programming
Matrix
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maximal_square_len = 0;
        int prev = 0;
        vector<int> row_val_dp(cols + 1);

        for(int r = 1; r <= rows; r++)
        {
            for(int c = 1; c <= cols; c++)
            {
                int temp = row_val_dp[c];
                if(matrix[r - 1][c - 1] == '1')
                {
                    row_val_dp[c] = min(min(row_val_dp[c - 1], prev), row_val_dp[c]) + 1;
                    maximal_square_len = max(row_val_dp[c], maximal_square_len);
                }
                else
                {
                    row_val_dp[c] = 0;
                }
                prev = temp;
            }
        }
        
        return maximal_square_len * maximal_square_len;
    }
};