/*
1572. Matrix Diagonal Sum
Easy
3K
39
company
Apple
company
Bloomberg
company
Amazon

Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

 

Example 1:

Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.

Example 2:

Input: mat = [[1,1,1,1],
              [1,1,1,1],
              [1,1,1,1],
              [1,1,1,1]]
Output: 8

Example 3:

Input: mat = [[5]]
Output: 5

 

Constraints:

    n == mat.length == mat[i].length
    1 <= n <= 100
    1 <= mat[i][j] <= 100

Accepted
269.1K
Submissions
325.2K
Acceptance Rate
82.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (28)
Similar Questions
Check if Every Row and Column Contains All Numbers
Easy
Check if Matrix Is X-Matrix
Easy
Related Topics
Array
Matrix
*/
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int diagonalSum = 0;

        for(int i = 0; i < n; i++)
            diagonalSum += mat[i][i] + mat[n - 1 - i][i];

        if(n & 1)   
            diagonalSum -= mat[n / 2][n / 2];

        return diagonalSum;
    }
};