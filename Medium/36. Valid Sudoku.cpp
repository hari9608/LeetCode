/*
36. Valid Sudoku
Medium
8.4K
895
company
Amazon
company
Apple
company
Karat

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:

    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules.

 

Example 1:

Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true

Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

 

Constraints:

    board.length == 9
    board[i].length == 9
    board[i][j] is a digit 1-9 or '.'.

Accepted
1.1M
Submissions
1.8M
Acceptance Rate
58.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (58)
Similar Questions
Sudoku Solver
Hard
Check if Every Row and Column Contains All Numbers
Easy
Related Topics
Array
Hash Table
Matrix
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int N = 9;

        vector<vector<int>> rows(N, vector<int>(N, 0));
        vector<vector<int>> cols(N, vector<int>(N, 0));
        vector<vector<int>> grid(N, vector<int>(N, 0));

        for(int row = 0; row < N; row++)
        {
            for(int col = 0; col < N; col++)
            {
                if(board[row][col] == '.')  continue;

                int pos = board[row][col] - '0' - 1;
                int ind = (row / 3) * 3 + col / 3;

                if(rows[row][pos] || cols[col][pos] || grid[ind][pos])  
                    return false;

                rows[row][pos] = 1;
                cols[col][pos] = 1;
                grid[ind][pos] = 1;
            }
        }

        return true;
    }
};
