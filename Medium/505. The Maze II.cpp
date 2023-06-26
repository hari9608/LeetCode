/*
505. The Maze II
Medium
1.2K
52
company
Amazon
company
Google
company
ByteDance

There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the m x n maze, the ball's start position and the destination, where start = [startrow, startcol] and destination = [destinationrow, destinationcol], return the shortest distance for the ball to stop at the destination. If the ball cannot stop at destination, return -1.

The distance is the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included).

You may assume that the borders of the maze are all walls (see examples).

 

Example 1:

Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
Output: 12
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
The length of the path is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.

Example 2:

Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
Output: -1
Explanation: There is no way for the ball to stop at the destination. Notice that you can pass through the destination but you cannot stop there.

Example 3:

Input: maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
Output: -1

 

Constraints:

    m == maze.length
    n == maze[i].length
    1 <= m, n <= 100
    maze[i][j] is 0 or 1.
    start.length == 2
    destination.length == 2
    0 <= startrow, destinationrow < m
    0 <= startcol, destinationcol < n
    Both the ball and the destination exist in an empty space, and they will not be in the same position initially.
    The maze contains at least 2 empty spaces.

Accepted
96.2K
Submissions
182.9K
Acceptance Rate
52.6%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (5)
Similar Questions
The Maze
Medium
The Maze III
Hard
Related Topics
Depth-First Search
Breadth-First Search
Graph
Heap (Priority Queue)
Shortest Path
*/
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int rows[4] = {-1, 0, 1, 0};
        int cols[4] = {0, 1, 0, -1};
        
        queue<pair<int, int>> to_visit;
        to_visit.push({start[0], start[1]});

        vector<vector<int>> distance(maze.size(), vector<int>(maze[0].size(), INT_MAX));
        distance[start[0]][start[1]] = 0;

        while(!to_visit.empty())
        {
            int start_row = to_visit.front().first;
            int start_col = to_visit.front().second;
            to_visit.pop();

            for(int dir = 0; dir < 4; dir++)
            {
                int next_row = start_row + rows[dir];
                int next_col = start_col + cols[dir];
                int count = 0;

                while(next_row >= 0 && next_row < maze.size() && next_col >= 0 && next_col < maze[0].size() && !maze[next_row][next_col])
                {
                    next_row = next_row + rows[dir];
                    next_col = next_col + cols[dir];
                    count++;
                }

                next_row = next_row - rows[dir];
                next_col = next_col - cols[dir];

                if(distance[start_row][start_col] + count < distance[next_row][next_col])
                {
                    to_visit.push({next_row, next_col});
                    distance[next_row][next_col] = distance[start_row][start_col] + count;
                }
            }
        }

        return distance[destination[0]][destination[1]] == INT_MAX ? -1 : distance[destination[0]][destination[1]];
    }
};