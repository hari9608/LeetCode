/*
465. Optimal Account Balancing
Hard
1.3K
125
company
Uber
company
Google
company
Amazon

You are given an array of transactions transactions where transactions[i] = [fromi, toi, amounti] indicates that the person with ID = fromi gave amounti $ to the person with ID = toi.

Return the minimum number of transactions required to settle the debt.

 

Example 1:

Input: transactions = [[0,1,10],[2,0,5]]
Output: 2
Explanation:
Person #0 gave person #1 $10.
Person #2 gave person #0 $5.
Two transactions are needed. One way to settle the debt is person #1 pays person #0 and #2 $5 each.

Example 2:

Input: transactions = [[0,1,10],[1,0,1],[1,2,5],[2,0,5]]
Output: 1
Explanation:
Person #0 gave person #1 $10.
Person #1 gave person #0 $1.
Person #1 gave person #2 $5.
Person #2 gave person #0 $5.
Therefore, person #1 only need to give person #0 $4, and all debt is settled.

 

Constraints:

    1 <= transactions.length <= 8
    transactions[i].length == 3
    0 <= fromi, toi < 12
    fromi != toi
    1 <= amounti <= 100

Accepted
81.4K
Submissions
164.8K
Acceptance Rate
49.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (15)
Related Topics
Array
Dynamic Programming
Backtracking
Bit Manipulation
Bitmask
*/

class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        int min_transfers = 0;
        map<int, int> credits_map;
        vector<int> credits;

        for(auto transaction : transactions)
        {
            credits_map[transaction[0]] += transaction[2];
            credits_map[transaction[1]] -= transaction[2];
        }

        for(auto credit : credits_map)
            if(credit.second)
                credits.push_back(credit.second);

        int cr_len = credits.size();
        vector<int> dp(1 << cr_len, -1);
        dp[0] = 0;

        return cr_len - dfs((1 << cr_len) - 1, dp, credits);
    }

    int dfs(int mask, vector<int>& dp, vector<int>& credits)
    {
        if(dp[mask] != -1)
            return dp[mask];

        int balance = 0;
        int res = 0;

        for(int ind = 0; ind < credits.size(); ind++)
        {
            int cur_bit = 1 << ind;

            if(mask & cur_bit)
            {
                balance += credits[ind];
                res = max(res, dfs(mask ^ cur_bit, dp, credits));
            }
        }
        
        dp[mask] = res + (balance ? 0 : 1);

        return dp[mask];
    }
};

/*
case 01
0 -> 1      -   10
1 -> 0      -   1

0   -10 +5  -5
1   +10     +10
2   -5      -5

case 02
0 -> 1      -   10
1 -> 0      -   1
1 -> 2      -   5
2 -> 0      -   5

0   -10 +5 +1       -4
1   -1 -5 +10       +4
2   -5 +5     0
*/