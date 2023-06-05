/*
200. Number of Islands
Medium
19.5K
434
company
Bloomberg
company
Amazon
company
Google

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 300
    grid[i][j] is '0' or '1'.

Accepted
2.1M
Submissions
3.7M
Acceptance Rate
57.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (69)
Similar Questions
Surrounded Regions
Medium
Walls and Gates
Medium
Number of Islands II
Hard
Number of Connected Components in an Undirected Graph
Medium
Number of Distinct Islands
Medium
Max Area of Island
Medium
Count Sub Islands
Medium
Find All Groups of Farmland
Medium
Count Unreachable Pairs of Nodes in an Undirected Graph
Medium
Related Topics
Array
Depth-First Search
Breadth-First Search
Union Find
Matrix
*/

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c, int nr, int nc)
    {
        grid[r][c] = '0';
        if(r-1 >= 0 && grid[r-1][c] == '1')    dfs(grid, r-1, c, nr, nc);
        if(r+1 < nr && grid[r+1][c] == '1')    dfs(grid, r+1, c, nr, nc);
        if(c-1 >= 0 && grid[r][c-1] == '1')    dfs(grid, r, c-1, nr, nc);
        if(c+1 < nc && grid[r][c+1] == '1')    dfs(grid, r, c+1, nr, nc);
    }

    int numIslands(vector<vector<char>>& grid) {
        int num_islands = 0;
        int nr = grid.size();
        if(!nr)                 
            return 0;

        int nc = grid[0].size();

        for(int r=0; r<nr; r++)
            for(int c=0; c<nc; c++)
                if(grid[r][c] == '1')
                {
                    num_islands++;
                    dfs(grid, r, c, nr, nc);
                }

        return num_islands;
    }
};