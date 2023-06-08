/*
566. Reshape the Matrix
Easy
3.3K
377
company
Apple
company
Bloomberg
company
Adobe

In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.

You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

 

Example 1:

Input: mat = [[1,2],[3,4]], r = 1, c = 4
Output: [[1,2,3,4]]

Example 2:

Input: mat = [[1,2],[3,4]], r = 2, c = 4
Output: [[1,2],[3,4]]

 

Constraints:

    m == mat.length
    n == mat[i].length
    1 <= m, n <= 100
    -1000 <= mat[i][j] <= 1000
    1 <= r, c <= 300

Accepted
349.2K
Submissions
554.7K
Acceptance Rate
63.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (21)
Similar Questions
Convert 1D Array Into 2D Array
Easy
Related Topics
Array
Matrix
Simulation
*/
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> reshaped_matrix(r, vector<int>(c));

        int mat_row = mat.size();
        int mat_col = mat[0].size();

        if(!mat_row || r * c != mat_row * mat_col)  
            return mat;

        int row = 0;
        int col = 0;

        for(int i=0; i<mat_row; i++)
            for(int j=0; j<mat_col; j++)
            {
                reshaped_matrix[row][col++] = mat[i][j];
                if(col == c)    
                    row++,  col = 0;
            }

        return reshaped_matrix;
    }
};