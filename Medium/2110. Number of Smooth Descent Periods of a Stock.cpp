/*
2110. Number of Smooth Descent Periods of a Stock
Medium
584
22
company
Amazon

You are given an integer array prices representing the daily price history of a stock, where prices[i] is the stock price on the ith day.

A smooth descent period of a stock consists of one or more contiguous days such that the price on each day is lower than the price on the preceding day by exactly 1. The first day of the period is exempted from this rule.

Return the number of smooth descent periods.

 

Example 1:

Input: prices = [3,2,1,4]
Output: 7
Explanation: There are 7 smooth descent periods:
[3], [2], [1], [4], [3,2], [2,1], and [3,2,1]
Note that a period with one day is a smooth descent period by the definition.

Example 2:

Input: prices = [8,6,7,7]
Output: 4
Explanation: There are 4 smooth descent periods: [8], [6], [7], and [7]
Note that [8,6] is not a smooth descent period as 8 - 6 ≠ 1.

Example 3:

Input: prices = [1]
Output: 1
Explanation: There is 1 smooth descent period: [1]

 

Constraints:

    1 <= prices.length <= 105
    1 <= prices[i] <= 105

Accepted
29.6K
Submissions
50.9K
Acceptance Rate
58.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (1)
Similar Questions
Subarray Product Less Than K
Medium
Number of Valid Subarrays
Hard
Number of Zero-Filled Subarrays
Medium
Related Topics
Array
Math
Dynamic Programming
*/
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long get_descent_periods = 0;
        long long present_descent = 1;

        for(int i=0; i<prices.size() - 1; i++)
        {
            if(prices[i]-1 == prices[i+1])
                present_descent++;
            else 
                if(present_descent > 1)
                    get_descent_periods += (long long)(present_descent * (present_descent + 1)) / 2,    present_descent = 1;
                else 
                    get_descent_periods += present_descent;
        }
        if(present_descent > 1)
        {
            get_descent_periods += (long long)(present_descent * (present_descent + 1)) / 2;
            return get_descent_periods;
        }

        return get_descent_periods + 1;
    }
};