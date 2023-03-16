/*
2352. Equal Row and Column Pairs
Medium
410
14
DE Shaw

Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

 

Example 1:

Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]

Example 2:

Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
Output: 3
Explanation: There are 3 equal row and column pairs:
- (Row 0, Column 0): [3,1,2,2]
- (Row 2, Column 2): [2,4,2,2]
- (Row 3, Column 2): [2,4,2,2]

 

Constraints:

    n == grid.length == grid[i].length
    1 <= n <= 200
    1 <= grid[i][j] <= 105

Accepted
33.5K
Submissions
47.5K
Acceptance Rate
70.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (2)
Similar Questions
Delete Greatest Value in Each Row
Easy
Related Topics
Array
Hash Table
Matrix
Simulation

*/
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int equal_pairs = 0;
        map<vector<int>, int> map_vec;

        for(auto gr : grid)     map_vec[gr]++;
        
        for(int row=0; row<grid.size(); row++)
        {
            vector<int> grid_col;
            for(int col=0; col<grid.size(); col++)
                grid_col.push_back(grid[col][row]);

            equal_pairs += map_vec[grid_col];
        }

        return equal_pairs;
    }
};