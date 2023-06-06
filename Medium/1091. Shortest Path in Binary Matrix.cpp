/*
1091. Shortest Path in Binary Matrix
Medium
5.6K
198
company
Facebook
company
Amazon
company
Google

Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

    All the visited cells of the path are 0.
    All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).

The length of a clear path is the number of visited cells of this path.

 

Example 1:

Input: grid = [[0,1],[1,0]]
Output: 2

Example 2:

Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1

 

Constraints:

    n == grid.length
    n == grid[i].length
    1 <= n <= 100
    grid[i][j] is 0 or 1

Accepted
358.8K
Submissions
773.8K
Acceptance Rate
46.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (56)
Similar Questions
Paths in Matrix Whose Sum Is Divisible by K
Hard
Related Topics
Array
Breadth-First Search
Matrix
*/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] || grid[n - 1][n - 1])
            return -1;
            
        int shortest_path_binary_matrix = 1;

        int rows[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int cols[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        
        queue<pair<int, int>> queue_l;
        queue_l.push({0, 0});
        grid[0][0] = 1;
        
        while(!queue_l.empty())
        {
            shortest_path_binary_matrix++;
            int que_len = queue_l.size();

            for(int i = 0; i < que_len; i++)
            {
                int r = queue_l.front().first;
                int c = queue_l.front().second;
                queue_l.pop();
                
                for(int i = 0; i < 8; i++)
                {
                    int nr = r + rows[i];
                    int nc = c + cols[i];

                    if(nr == n - 1 && nc == n - 1)
                        return shortest_path_binary_matrix;
                    
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && !grid[nr][nc])
                    {
                        grid[nr][nc] = 1;
                        queue_l.push({nr, nc});
                    }
                }
            }
        }

        return grid[n - 1][n - 1] ? shortest_path_binary_matrix - 1 : -1;
    }
};