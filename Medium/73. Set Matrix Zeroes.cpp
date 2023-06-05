/*
73. Set Matrix Zeroes
Medium
11.1K
612
company
Amazon
company
Bloomberg
company
Microsoft

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

 

Constraints:

    m == matrix.length
    n == matrix[0].length
    1 <= m, n <= 200
    -231 <= matrix[i][j] <= 231 - 1

 

Follow up:

    A straightforward solution using O(mn) space is probably a bad idea.
    A simple improvement uses O(m + n) space, but still not the best solution.
    Could you devise a constant space solution?

Accepted
964.5K
Submissions
1.9M
Acceptance Rate
51.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (22)
Similar Questions
Game of Life
Medium
Number of Laser Beams in a Bank
Medium
Minimum Operations to Remove Adjacent Ones in Matrix
Hard
Remove All Ones With Row and Column Flips II
Medium
Related Topics
Array
Hash Table
Matrix
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int zero_col = 0;
        int row_size = matrix.size();
        int col_size = matrix[0].size();

        for(int r=0; r<row_size; r++)
        {
            if(!matrix[r][0])   zero_col = 1;
            for(int c=1; c<col_size; c++)
                if(!matrix[r][c])
                    matrix[r][0] = matrix[0][c] = 0;
        }

        for(int r=row_size-1; r>=0; r--)
        {
            for(int c=col_size-1; c>0; c--)
                if(!matrix[0][c] || !matrix[r][0])      matrix[r][c] = 0;
            if(zero_col)                                matrix[r][0] = 0;
        }

        return;
    }
};