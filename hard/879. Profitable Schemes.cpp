/*879. Profitable Schemes
Hard
1.7K
114
company
Google

There is a group of n members, and a list of various crimes they could commit. The ith crime generates a profit[i] and requires group[i] members to participate in it. If a member participates in one crime, that member can't participate in another crime.

Let's call a profitable scheme any subset of these crimes that generates at least minProfit profit, and the total number of members participating in that subset of crimes is at most n.

Return the number of schemes that can be chosen. Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: n = 5, minProfit = 3, group = [2,2], profit = [2,3]
Output: 2
Explanation: To make a profit of at least 3, the group could either commit crimes 0 and 1, or just crime 1.
In total, there are 2 schemes.

Example 2:

Input: n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8]
Output: 7
Explanation: To make a profit of at least 5, the group could commit any crimes, as long as they commit one.
There are 7 possible schemes: (0), (1), (2), (0,1), (0,2), (1,2), and (0,1,2).

 

Constraints:

    1 <= n <= 100
    0 <= minProfit <= 100
    1 <= group.length <= 100
    1 <= group[i] <= 100
    profit.length == group.length
    0 <= profit[i] <= 100

Accepted
56.9K
Submissions
115K
Acceptance Rate
49.5%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (35)
Related Topics
Array
Dynamic Programming
*/
class Solution {
public:
    int mod = 1e9 + 7;
    int dp[101][101][101];
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        for (int count = 0; count <= n; count++) 
            dp[group.size()][count][minProfit] = 1;

        for (int ind = group.size() - 1; ind >= 0; ind--) 
            for (int count = 0; count <= n; count++) 
                for(int gain = 0; gain <= minProfit; gain++) 
                {
                    dp[ind][count][gain] = dp[ind + 1][count][gain];
                    if (count + group[ind] <= n) 
                        dp[ind][count][gain] = (dp[ind][count][gain] + dp[ind + 1][count + group[ind]][min(minProfit, gain + profit[ind])]) % mod;
                }
        
        return dp[0][0][0];
    }
};