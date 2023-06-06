/*
122. Best Time to Buy and Sell Stock II
Medium
11.2K
2.5K
company
Citadel
company
Amazon
company
Bloomberg

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

 

Constraints:

    1 <= prices.length <= 3 * 104
    0 <= prices[i] <= 104

Accepted
1.5M
Submissions
2.3M
Acceptance Rate
64.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (58)
Similar Questions
Best Time to Buy and Sell Stock
Easy
Best Time to Buy and Sell Stock III
Hard
Best Time to Buy and Sell Stock IV
Hard
Best Time to Buy and Sell Stock with Cooldown
Medium
Best Time to Buy and Sell Stock with Transaction Fee
Medium
Maximum Profit From Trading Stocks
Medium
Related Topics
Array
Dynamic Programming
Greedy
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        
        for (int i = 1; i < prices.size(); i++) 
            if (prices[i] > prices[i - 1])
                maxprofit += prices[i] - prices[i - 1];
        
        return maxprofit;
    }
};