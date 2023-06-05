/*
322. Coin Change
Medium
15.8K
360
company
Amazon
company
Bloomberg
company
Apple

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1

Example 3:

Input: coins = [1], amount = 0
Output: 0

 

Constraints:

    1 <= coins.length <= 12
    1 <= coins[i] <= 231 - 1
    0 <= amount <= 104

Accepted
1.4M
Submissions
3.2M
Acceptance Rate
42.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (41)
Similar Questions
Minimum Cost For Tickets
Medium
Maximum Value of K Coins From Piles
Hard
Minimum Number of Operations to Convert Time
Easy
Minimum Cost to Split an Array
Hard
Related Topics
Array
Dynamic Programming
Breadth-First Search
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int max = amount + 1;
        vector<int> coin_change(max, max);
        coin_change[0] = 0;
        
        for(int i=1; i<=amount; i++)
            for(int j=0; j<coins.size(); j++)
                if(coins[j] <= i) 
                    coin_change[i] = min(coin_change[i], coin_change[i - coins[j]] + 1);
                    
        return coin_change[amount] > amount ? -1 : coin_change[amount];
    }
};