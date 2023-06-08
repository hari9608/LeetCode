/*
121. Best Time to Buy and Sell Stock
Easy
25.7K
808
company
Amazon
company
Apple
company
Facebook

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

 

Constraints:

    1 <= prices.length <= 105
    0 <= prices[i] <= 104

Accepted
3.4M
Submissions
6.2M
Acceptance Rate
54.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (152)
Similar Questions
Maximum Subarray
Medium
Best Time to Buy and Sell Stock II
Medium
Best Time to Buy and Sell Stock III
Hard
Best Time to Buy and Sell Stock IV
Hard
Best Time to Buy and Sell Stock with Cooldown
Medium
Sum of Beauty in the Array
Medium
Maximum Difference Between Increasing Elements
Easy
Maximum Profit From Trading Stocks
Medium
Related Topics
Array
Dynamic Programming
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = prices[0];
        for(int val: prices){
            if(val < minPrice)  minPrice = val;
            if(val - minPrice > maxProfit) maxProfit = val - minPrice;
        }
        return maxProfit;
    }
};