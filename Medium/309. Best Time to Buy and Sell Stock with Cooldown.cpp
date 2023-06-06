/*
309. Best Time to Buy and Sell Stock with Cooldown
Medium
8.4K
281
company
Amazon
company
Adobe
company
Bloomberg

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

    After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Example 2:

Input: prices = [1]
Output: 0

 

Constraints:

    1 <= prices.length <= 5000
    0 <= prices[i] <= 1000

Accepted
409.6K
Submissions
725.3K
Acceptance Rate
56.5%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (27)
Similar Questions
Best Time to Buy and Sell Stock
Easy
Best Time to Buy and Sell Stock II
Medium
Related Topics
Array
Dynamic Programming
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = INT_MIN;
        int held = INT_MIN;
        int reset = 0;

        for (int price : prices) 
        {
            int preSold = sold;

            sold = held + price;
            held = max(held, reset - price);
            reset = max(reset, preSold);
        }

        return max(sold, reset);
    }
};