/*
1314. Matrix Block Sum
Medium
2.2K
339
company
Microsoft
company
Amazon
company
Google

Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:

    i - k <= r <= i + k,
    j - k <= c <= j + k, and
    (r, c) is a valid position in the matrix.

 

Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]

Example 2:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]

 

Constraints:

    m == mat.length
    n == mat[i].length
    1 <= m, n, k <= 100
    1 <= mat[i][j] <= 100

Accepted
78.6K
Submissions
104.2K
Acceptance Rate
75.5%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (10)
Similar Questions
Stamping the Grid
Hard
Maximum Sum of an Hourglass
Medium
Related Topics
Array
Matrix
Prefix Sum
*/
class Solution {
public:
    vector<vector<int>> presum;
    int solve(vector<vector<int>>&ans,int row1, int col1, int row2, int col2) 
    {
        int sum = 0;
        sum += presum[row2][col2];

        if(col1 > 0) 
            sum -= presum[row2][col1-1];
        if(row1 > 0) 
            sum -= presum[row1-1][col2];
        if(col1 > 0 && row1 > 0) 
            sum += presum[row1-1][col1-1];

        return sum;
    }

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        presum = matrix;
        vector<vector<int>> matrix_block_sum(rows, vector<int>(cols, 0));
        
        for(int c = 1; c < cols; c++)
            presum[0][c] += presum[0][c - 1];

        for(int r = 1; r < rows; r++)
            presum[r][0] += presum[r - 1][0];
        
        for(int r = 1; r < rows; r++)
            for(int c = 1; c < cols; c++)
                presum[r][c] += presum[r - 1][c] + presum[r][c - 1] - presum[r - 1][c - 1];
        
        for(int r = 0; r < rows; r++)
            for(int c = 0; c < cols; c++)
                matrix_block_sum[r][c] = solve( matrix_block_sum, 
                                        (r < k) ? 0 : r - k, 
                                        (c < k) ? 0 : c - k, 
                                        (r + k) >= rows ? rows - 1 : r + k, 
                                        (c + k) >= cols ? cols - 1 : c + k);

        return matrix_block_sum;
    }
};