/*
714. Best Time to Buy and Sell Stock with Transaction Fee
Medium
5.3K
132
company
Amazon
company
Adobe
company
Apple

You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6

 

Constraints:

    1 <= prices.length <= 5 * 104
    1 <= prices[i] < 5 * 104
    0 <= fee < 5 * 104

Accepted
232.1K
Submissions
354.2K
Acceptance Rate
65.5%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (12)
Similar Questions
Best Time to Buy and Sell Stock II
Medium
Related Topics
Array
Dynamic Programming
Greedy
*/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0;
        int hold = -prices[0];

        for (int i = 1; i < prices.size(); i++) 
        {
            cash = max(cash, hold + prices[i] - fee);
            hold = max(hold, cash - prices[i]);
        }

        return cash;
    }
};