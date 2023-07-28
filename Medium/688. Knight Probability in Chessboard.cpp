/*
688. Knight Probability in Chessboard
Medium
3.6K
439
company
Amazon
company
Goldman Sachs
company
Microsoft

On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).

A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.

Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly k moves or has moved off the chessboard.

Return the probability that the knight remains on the board after it has stopped moving.

 

Example 1:

Input: n = 3, k = 2, row = 0, column = 0
Output: 0.06250
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.

Example 2:

Input: n = 1, k = 0, row = 0, column = 0
Output: 1.00000

 

Constraints:

    1 <= n <= 25
    0 <= k <= 100
    0 <= row, column <= n - 1

Accepted
140.9K
Submissions
250.4K
Acceptance Rate
56.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (42)
Similar Questions
Out of Boundary Paths
Medium
Related Topics
Dynamic Programming
*/
class Solution {
public:     
    double knightProbability(int n, int k, int row, int column) {        
        vector<pair<int, int>> directions = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};   

        vector prevDp(n, vector<double>(n, 0));    
        vector currDp(n, vector<double>(n, 0));        

        prevDp[row][column] = 1;        
        for (int moves = 1; moves <= k; moves++) 
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++) 
                {
                    currDp[i][j] = 0;                     

                    for (const auto& direction : directions) 
                    {
                        int prevI = i - direction.first;                       
                        int prevJ = j - direction.second;                        

                        if (prevI >= 0 && prevI < n && prevJ >= 0 && prevJ < n) 
                            currDp[i][j] += prevDp[prevI][prevJ] / 8;                        
                    }                
                }           
            }              
        
            prevDp.swap(currDp);       
        }        
    
        double totalProbability = 0;

        for(const auto& row : prevDp)
            for(const auto& cell : row)
                totalProbability += cell;   
        
        return totalProbability;    
    }
};