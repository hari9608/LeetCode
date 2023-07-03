/*
542. 01 Matrix
Medium
7.4K
340
company
Microsoft
company
Google
company
Amazon

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:

Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:

Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

 

Constraints:

    m == mat.length
    n == mat[i].length
    1 <= m, n <= 104
    1 <= m * n <= 104
    mat[i][j] is either 0 or 1.
    There is at least one 0 in mat.

Accepted
396.9K
Submissions
878.2K
Acceptance Rate
45.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (18)
Similar Questions
Shortest Path to Get Food
Medium
Minimum Operations to Remove Adjacent Ones in Matrix
Hard
Difference Between Ones and Zeros in Row and Column
Medium
Related Topics
Array
Dynamic Programming
Breadth-First Search
Matrix
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> update_matrix(m, vector<int>(n, -1));        
        queue<vector<int>> que;

        for(int r = 0; r < m; r++)
            for(int c = 0; c < n; c++)
                if(!mat[r][c])
                {
                    update_matrix[r][c] = 0;
                    que.push({r, c, 0});
                }
        
        while(!que.empty())
        {
            int cur_row = que.front()[0];
            int cur_col = que.front()[1];
            int cur_dis = que.front()[2];
            que.pop();

            for(auto dir : directions)
            {
                int new_row = cur_row + dir[0];
                int new_col = cur_col + dir[1];
                
                if(new_row >= 0 && new_row < m && new_col >= 0 && new_col < n && update_matrix[new_row][new_col] == -1)
                {
                    update_matrix[new_row][new_col] = 1 + cur_dis;
                    que.push({new_row, new_col, cur_dis + 1});
                }
            }
        }

        return update_matrix;
    }
};