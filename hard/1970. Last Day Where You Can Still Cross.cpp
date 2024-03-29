/*
1970. Last Day Where You Can Still Cross
Hard
1.3K
25

There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.

Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).

You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).

Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.

 

Example 1:

Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
Output: 2
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 2.

Example 2:

Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
Output: 1
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 1.

Example 3:

Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
Output: 3
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 3.

 

Constraints:

    2 <= row, col <= 2 * 104
    4 <= row * col <= 2 * 104
    cells.length == row * col
    1 <= ri <= row
    1 <= ci <= col
    All the values of cells are unique.

Accepted
31.4K
Submissions
52.3K
Acceptance Rate
60.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (55)
Similar Questions
Bricks Falling When Hit
Hard
Escape the Spreading Fire
Hard
Related Topics
Array
Binary Search
Depth-First Search
Breadth-First Search
Union Find
Matrix
*/

class Solution {
public:
    bool crossed(int row, int col, vector<vector<int>>& cells, int day)
    {
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> grid(row, vector<int>(col, 0));
        queue<pair<int, int>> que;

        // mark the water in land grid
        for(int ind = 0; ind < day; ind++)
            grid[cells[ind][0] - 1][cells[ind][1] - 1] = 1;

        // find the land on the top row and push 
        for(int ind = 0; ind < col; ind++)
        {
            if(!grid[0][ind])
            {
                que.push({0, ind});
                grid[0][ind] = -1;
            }
        }

        // travel until reach bottom of the grid (r == row - 1)
        while(!que.empty())
        {
            int r = que.front().first;
            int c = que.front().second;
            que.pop();

            if(r == row - 1)
                return true;

            for(auto move : dir)
            {
                int next_row = r + move[0];
                int next_col = c + move[1];

                if(next_row >= 0 && next_row < row && next_col >= 0 && next_col < col && !grid[next_row][next_col])
                {
                    que.push({next_row, next_col});
                    grid[next_row][next_col] = -1;
                }
            }
        }

        return false;
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1;
        int right = row * col;

        while(left < right)
        {
            int mid = right - (right - left) / 2;

            if(crossed(row, col, cells, mid))
                left = mid;
            else
                right = mid - 1;
        }

        return left;
    }
};