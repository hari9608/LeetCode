/*
1230. Toss Strange Coins
Medium
366
43
company
Google
company
Twitch

You have some coins.  The i-th coin has a probability prob[i] of facing heads when tossed.

Return the probability that the number of coins facing heads equals target if you toss every coin exactly once.

 

Example 1:

Input: prob = [0.4], target = 1
Output: 0.40000

Example 2:

Input: prob = [0.5,0.5,0.5,0.5,0.5], target = 0
Output: 0.03125

 

Constraints:

    1 <= prob.length <= 1000
    0 <= prob[i] <= 1
    0 <= target <= prob.length
    Answers will be accepted as correct if they are within 10^-5 of the correct answer.

Accepted
16.3K
Submissions
29K
Acceptance Rate
56.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (4)
Related Topics
Math
Dynamic Programming
Probability and Statistics
*/
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<double> dp(target + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) 
        {
            for (int j = target; j >= 1; j--) 
                dp[j] = dp[j - 1] * prob[i - 1] + dp[j] * (1 - prob[i - 1]);

            dp[0] = dp[0] * (1 - prob[i - 1]);
        }

        return dp[target];
    }
};