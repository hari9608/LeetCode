/*
920. Number of Music Playlists
Hard
2.1K
183
company
Google
Coursera

Your music player contains n different songs. You want to listen to goal songs (not necessarily different) during your trip. To avoid boredom, you will create a playlist so that:

    Every song is played at least once.
    A song can only be played again only if k other songs have been played.

Given n, goal, and k, return the number of possible playlists that you can create. Since the answer can be very large, return it modulo 109 + 7.

 

Example 1:

Input: n = 3, goal = 3, k = 1
Output: 6
Explanation: There are 6 possible playlists: [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], and [3, 2, 1].

Example 2:

Input: n = 2, goal = 3, k = 0
Output: 6
Explanation: There are 6 possible playlists: [1, 1, 2], [1, 2, 1], [2, 1, 1], [2, 2, 1], [2, 1, 2], and [1, 2, 2].

Example 3:

Input: n = 2, goal = 3, k = 1
Output: 2
Explanation: There are 2 possible playlists: [1, 2, 1] and [2, 1, 2].

 

Constraints:

    0 <= k < n <= goal <= 100

Accepted
62.6K
Submissions
102.1K
Acceptance Rate
61.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (38)
Similar Questions
Count the Number of Good Subsequences
Medium
Related Topics
Math
Dynamic Programming
Combinatorics
*/

class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long>> dp(goal + 1, vector<long>(n + 1, 0));
        int mod = 1e9 + 7;
        
        dp[0][0] = 1;

        for(int g = 1; g <= goal; g++)
            for(int j = 1; j <= min(g, n); j++)
            {
                dp[g][j] = dp[g - 1][j - 1] * (n - j + 1) % mod;

                if(g > k)
                    dp[g][j] = (dp[g][j] + dp[g - 1][j] * (j - k)) % mod;
            }

        return dp[goal][n];
    }
};