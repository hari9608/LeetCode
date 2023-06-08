/*
2133. Check if Every Row and Column Contains All Numbers
Easy
817
45
company
Karat
instacart

An n x n matrix is valid if every row and every column contains all the integers from 1 to n (inclusive).

Given an n x n integer matrix matrix, return true if the matrix is valid. Otherwise, return false.

 

Example 1:

Input: matrix = [[1,2,3],[3,1,2],[2,3,1]]
Output: true
Explanation: In this case, n = 3, and every row and column contains the numbers 1, 2, and 3.
Hence, we return true.

Example 2:

Input: matrix = [[1,1,1],[1,2,3],[1,2,3]]
Output: false
Explanation: In this case, n = 3, but the first row and the first column do not contain the numbers 2 or 3.
Hence, we return false.

 

Constraints:

    n == matrix.length == matrix[i].length
    1 <= n <= 100
    1 <= matrix[i][j] <= n

Accepted
55.1K
Submissions
106.4K
Acceptance Rate
51.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (6)
Similar Questions
Valid Sudoku
Medium
Matrix Diagonal Sum
Easy
First Completely Painted Row or Column
Medium
Related Topics
Array
Hash Table
Matrix
*/
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0; i<n; i++)
        {
            set<int> row_set;
            set<int> col_set;

            for(int r=0; r<n; r++)      col_set.insert(matrix[r][i]);

            for(int c=0; c<n; c++)      row_set.insert(matrix[i][c]);

            if(row_set.size() != n || col_set.size() != n)      return false;            
        }

        return true;
    }
};