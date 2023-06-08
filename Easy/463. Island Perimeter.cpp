/*
463. Island Perimeter
Easy
5.7K
277
company
Apple
company
Facebook
company
Bloomberg

You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example 1:

Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.

Example 2:

Input: grid = [[1]]
Output: 4

Example 3:

Input: grid = [[1,0]]
Output: 4

 

Constraints:

    row == grid.length
    col == grid[i].length
    1 <= row, col <= 100
    grid[i][j] is 0 or 1.
    There is exactly one island in grid.

Accepted
438K
Submissions
628.1K
Acceptance Rate
69.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (9)
Similar Questions
Max Area of Island
Medium
Flood Fill
Easy
Coloring A Border
Medium
Related Topics
Array
Depth-First Search
Breadth-First Search
Matrix
*/
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int island_perimeter = 0;
        int row = grid.size();
        int col = grid[0].size();

        for(int r = 0; r < row; r++)
            for(int c = 0; c < col; c++)
                if(grid[r][c])
                {
                    island_perimeter += 4;

                    if(r && grid[r - 1][c])
                        island_perimeter -= 2;

                    if(c && grid[r][c - 1])
                        island_perimeter -= 2;
                }

        return island_perimeter;
    }
};