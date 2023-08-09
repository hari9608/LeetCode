/*
712. Minimum ASCII Delete Sum for Two Strings
Medium
3.7K
97
TripleByte

Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

 

Example 1:

Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

Example 2:

Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d] + 101[e] + 101[e] to the sum.
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.

 

Constraints:

    1 <= s1.length, s2.length <= 1000
    s1 and s2 consist of lowercase English letters.

Accepted
129.5K
Submissions
199.5K
Acceptance Rate
64.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (48)
Similar Questions
Edit Distance
Medium
Longest Increasing Subsequence
Medium
Delete Operation for Two Strings
Medium
Related Topics
String
Dynamic Programming
*/

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int s1_len = s1.length();
        int s2_len = s2.length();
        vector<vector<int>> compute_cost(s1_len + 1, vector<int>(s2_len + 1));

        for (int i = 1; i <= s1_len; i++)
            compute_cost[i][0] = compute_cost[i - 1][0] + s1[i - 1];
    
        for (int j = 1; j <= s2_len; j++)
            compute_cost[0][j] = compute_cost[0][j - 1] + s2[j - 1];
        
        for (int i = 1; i <= s1_len; i++) 
            for (int j = 1; j <= s2_len; j++) 
                if (s1[i - 1] == s2[j - 1])
                    compute_cost[i][j] = compute_cost[i - 1][j - 1];
                else
                    compute_cost[i][j] = min(   s1[i - 1] + compute_cost[i - 1][j], 
                                                s2[j - 1] + compute_cost[i][j - 1]);
        
        return compute_cost[s1_len][s2_len];
    }
};