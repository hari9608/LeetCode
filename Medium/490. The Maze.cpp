/*
490. The Maze
Medium
1.7K
169
company
TikTok
company
Square
company
Amazon

There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the m x n maze, the ball's start position and the destination, where start = [startrow, startcol] and destination = [destinationrow, destinationcol], return true if the ball can stop at the destination, otherwise return false.

You may assume that the borders of the maze are all walls (see examples).

 

Example 1:

Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.

Example 2:

Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
Output: false
Explanation: There is no way for the ball to stop at the destination. Notice that you can pass through the destination but you cannot stop there.

Example 3:

Input: maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
Output: false

 

Constraints:

    m == maze.length
    n == maze[i].length
    1 <= m, n <= 100
    maze[i][j] is 0 or 1.
    start.length == 2
    destination.length == 2
    0 <= startrow, destinationrow <= m
    0 <= startcol, destinationcol <= n
    Both the ball and the destination exist in an empty space, and they will not be in the same position initially.
    The maze contains at least 2 empty spaces.

Accepted
145K
Submissions
258.9K
Acceptance Rate
56.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (14)
Similar Questions
The Maze III
Hard
The Maze II
Medium
Related Topics
Depth-First Search
Breadth-First Search
Graph
*/
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        int rows[4] = {-1, 0, 1, 0};
        int cols[4] = {0, 1, 0, -1};
        
        queue<pair<int, int>> to_visit;
        to_visit.push({start[0], start[1]});

        while(!to_visit.empty())
        {
            int start_row = to_visit.front().first;
            int start_col = to_visit.front().second;
            to_visit.pop();

            maze[start_row][start_col] = 3;

            for(int dir = 0; dir < 4; dir++)
            {
                int next_row = start_row + rows[dir];
                int next_col = start_col + cols[dir];

                while(next_row >= 0 && next_row < m && next_col >= 0 && next_col < n && maze[next_row][next_col] != 1)
                {
                    next_row = next_row + rows[dir];
                    next_col = next_col + cols[dir];
                }

                next_row = next_row - rows[dir];
                next_col = next_col - cols[dir];

                if(maze[next_row][next_col] == 2 || maze[next_row][next_col] == 0)
                    to_visit.push({next_row, next_col});
            }
        }

        return maze[destination[0]][destination[1]] == 3;
    }
};