/*
864. Shortest Path to Get All Keys
Hard
2K
93
company
Airbnb
company
Palantir Technologies
company
ByteDance

You are given an m x n grid grid where:

    '.' is an empty cell.
    '#' is a wall.
    '@' is the starting point.
    Lowercase letters represent keys.
    Uppercase letters represent locks.

You start at the starting point and one move consists of walking one space in one of the four cardinal directions. You cannot walk outside the grid, or walk into a wall.

If you walk over a key, you can pick it up and you cannot walk over a lock unless you have its corresponding key.

For some 1 <= k <= 6, there is exactly one lowercase and one uppercase letter of the first k letters of the English alphabet in the grid. This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.

Return the lowest number of moves to acquire all keys. If it is impossible, return -1.

 

Example 1:

Input: grid = ["@.a..","###.#","b.A.B"]
Output: 8
Explanation: Note that the goal is to obtain all the keys not to open all the locks.

Example 2:

Input: grid = ["@..aA","..B#.","....b"]
Output: 6

Example 3:

Input: grid = ["@Aa"]
Output: -1

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 30
    grid[i][j] is either an English letter, '.', '#', or '@'.
    The number of keys in the grid is in the range [1, 6].
    Each key in the grid is unique.
    Each key in the grid has a matching lock.

Accepted
65.2K
Submissions
119.5K
Acceptance Rate
54.5%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (78)
Related Topics
Array
Bit Manipulation
Breadth-First Search
Matrix
*/

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int shortest_path_all_keys = 0;

        vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        
        queue<vector<int>> que;
        map<int, set<pair<int, int>>> visit;        
        set<char> keys;
        set<char> locks;

        int all_keys = 0;
        int start_row = -1;
        int start_col = -1;

        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                char cell = grid[r][c];

                if(cell >= 'a' && cell <= 'f')
                {
                    all_keys += (1 << (cell - 'a'));
                    keys.insert(cell);
                }

                if(cell >= 'A' && cell <= 'F')
                    locks.insert(cell);

                if(cell == '@')
                {
                    start_row = r;
                    start_col = c;
                }
            }
        }

        que.push({start_row, start_col, 0, 0});
        visit[0].insert({start_row, start_col});

        while(!que.empty())
        {
            auto q = que.front();
            int cur_row = q[0];
            int cur_col = q[1];
            int key = q[2];
            int dist = q[3];
            que.pop();

            for(auto move : dir)
            {
                int next_row = cur_row + move[0];
                int next_col = cur_col + move[1];
                
                if(next_row >= 0 && next_row < rows && next_col >= 0 && next_col < cols && grid[next_row][next_col] != '#')
                {
                    char cell = grid[next_row][next_col];
                    
                    // if cell contains key then 
                    if(keys.count(cell))
                    {
                        if(((1 << (cell - 'a')) & key))
                            continue;

                        int new_key = (key | (1 << (cell - 'a')));

                        if(new_key == all_keys)
                            return dist + 1;

                        visit[new_key].insert({next_row, next_col});
                        que.push({next_row, next_col, new_key, dist + 1});
                    }

                    // if cell contains lock then
                    if(locks.count(cell) && !(key & (1 << (cell - 'A'))))
                        continue;

                    else if(!visit[key].count({next_row, next_col}))
                    {
                        visit[key].insert({next_row, next_col});
                        que.push({next_row, next_col, key, dist + 1});
                    }
                }
            }
        }

        return -1;
    }
};