/*
1140. Stone Game II
Medium
2.5K
573
company
Uber
company
Bloomberg

Alice and Bob continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones. 

Alice and Bob take turns, with Alice starting first.  Initially, M = 1.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

 

Example 1:

Input: piles = [2,7,9,4,4]
Output: 10
Explanation:  If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total. If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10 since it's larger. 

Example 2:

Input: piles = [1,2,3,4,5,100]
Output: 104

 

Constraints:

    1 <= piles.length <= 100
    1 <= piles[i] <= 104

Accepted
82.8K
Submissions
120.4K
Acceptance Rate
68.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (63)
Similar Questions
Stone Game V
Hard
Stone Game VI
Medium
Stone Game VII
Medium
Stone Game VIII
Hard
Stone Game IX
Medium
Related Topics
Array
Math
Dynamic Programming
Game Theory
*/
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int piles_len = piles.size();
        vector<vector<int>> dp(piles_len + 1, vector<int>(piles_len + 1, 0));
        vector<int> piles_sum (piles_len + 1, 0);

        for (int i = piles_len - 1; i >= 0; i--) 
            piles_sum[i] = piles_sum[i + 1] + piles[i];
        
        for (int i = 0; i <= piles_len; i++) 
            dp[i][piles_len] = piles_sum[i];
        
        for (int i = piles_len - 1; i >= 0; i--) 
            for (int j = piles_len - 1; j >= 1; j--) 
                for (int X = 1; X <= 2 * j && i + X <= piles_len; X++) 
                    dp[i][j] = max(dp[i][j], piles_sum[i] - dp[i + X][max(j, X)]);
                    
        return dp[0][1];
    }
};