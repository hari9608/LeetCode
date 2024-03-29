/*
1444. Number of Ways of Cutting a Pizza
Hard
1.6K
90
company
TikTok
company
ByteDance
company
Google

Given a rectangular pizza represented as a rows x cols matrix containing the following characters: 'A' (an apple) and '.' (empty cell) and given the integer k. You have to cut the pizza into k pieces using k-1 cuts. 

For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to a person. Give the last piece of pizza to the last person.

Return the number of ways of cutting the pizza such that each piece contains at least one apple. Since the answer can be a huge number, return this modulo 10^9 + 7.

 

Example 1:

Input: pizza = ["A..","AAA","..."], k = 3
Output: 3 
Explanation: The figure above shows the three ways to cut the pizza. Note that pieces must contain at least one apple.

Example 2:

Input: pizza = ["A..","AA.","..."], k = 3
Output: 1

Example 3:

Input: pizza = ["A..","A..","..."], k = 1
Output: 1

 

Constraints:

    1 <= rows, cols <= 50
    rows == pizza.length
    cols == pizza[i].length
    1 <= k <= 10
    pizza consists of characters 'A' and '.' only.

Accepted
60.3K
Submissions
94.2K
Acceptance Rate
64.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (73)
Similar Questions
Selling Pieces of Wood
Hard
Related Topics
Array
Dynamic Programming
Memoization
Matrix
*/
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int rows = pizza.size();
        int cols = pizza[0].size();

        vector apples(rows + 1, vector<int>(cols + 1));
        vector f(rows, vector<int>(cols));

        for(int row = rows - 1; row >= 0; row--)
            for(int col = cols - 1; col >= 0; col--)
            {
                apples[row][col] = (pizza[row][col] == 'A') + apples[row + 1][col] + apples[row][col + 1] - apples[row + 1][col + 1];
                f[row][col] = apples[row][col] > 0;
            }

        const int mod = 1000000007;

        for(int remain = 1; remain < k; remain++)
        {
            vector g(rows, vector<int>(cols));

            for(int row = 0; row < rows; row++)
                for(int col = 0; col < cols; col++)
                {
                    for(int next_row = row + 1; next_row < rows; next_row++)
                        if(apples[row][col] - apples[next_row][col] > 0)
                            (g[row][col] += f[next_row][col]) %= mod;

                    for(int next_col = col + 1; next_col < cols; next_col++)
                        if(apples[row][col] - apples[row][next_col] > 0)
                            (g[row][col] += f[row][next_col]) %= mod;
                }

            f = g;
        }

        return f[0][0];
    }
};