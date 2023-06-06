/*
1406. Stone Game III
Hard
2K
67
company
Google

Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2, or 3 stones from the first remaining stones in the row.

The score of each player is the sum of the values of the stones taken. The score of each player is 0 initially.

The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.

Assume Alice and Bob play optimally.

Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they will end the game with the same score.

 

Example 1:

Input: stoneValue = [1,2,3,7]
Output: "Bob"
Explanation: Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7 and Bob wins.

Example 2:

Input: stoneValue = [1,2,3,-9]
Output: "Alice"
Explanation: Alice must choose all the three piles at the first move to win and leave Bob with negative score.
If Alice chooses one pile her score will be 1 and the next move Bob's score becomes 5. In the next move, Alice will take the pile with value = -9 and lose.
If Alice chooses two piles her score will be 3 and the next move Bob's score becomes 3. In the next move, Alice will take the pile with value = -9 and also lose.
Remember that both play optimally so here Alice will choose the scenario that makes her win.

Example 3:

Input: stoneValue = [1,2,3,6]
Output: "Tie"
Explanation: Alice cannot win this game. She can end the game in a draw if she decided to choose all the first three piles, otherwise she will lose.

 

Constraints:

    1 <= stoneValue.length <= 5 * 104
    -1000 <= stoneValue[i] <= 1000

Accepted
78.6K
Submissions
120.8K
Acceptance Rate
65.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (54)
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
    string stoneGameIII(vector<int>& stoneValue) {
        int stone_len = stoneValue.size();
        vector<int> dp(stone_len + 1, 0);

        for(int i = stone_len - 1; i >= 0; i--)
        {
            dp[i] = stoneValue[i] - dp[i + 1];
            
            if(i + 2 <= stone_len)
                dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] - dp[i + 2]);

            if(i + 3 <= stone_len)
                dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3]);
        }
        
        return !dp[0] ? "Tie" : dp[0] < 0 ? "Bob" : "Alice";
    }
};