/*1312. Minimum Insertion Steps to Make a String Palindrome
Hard
4.2K
58
company
Amazon
company
Adobe
company
Microsoft

Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.

Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".

Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".

 

Constraints:

    1 <= s.length <= 500
    s consists of lowercase English letters.

Accepted
122.2K
Submissions
176.6K
Acceptance Rate
69.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (46)
Similar Questions
Minimum Number of Moves to Make Palindrome
Hard
Related Topics
String
Dynamic Programming
*/
class Solution {
public:
    int lcs(string& s1, string& s2, int m, int n) {
        vector<int> dp(n + 1);
        vector<int> dpPrev(n + 1);

        for (int i = 0; i <= m; i++) 
        {
            for (int j = 0; j <= n; j++) 
                if (i == 0 || j == 0) 
                    dp[j] = 0;
                else if (s1[i - 1] == s2[j - 1]) 
                    dp[j] = 1 + dpPrev[j - 1];
                else 
                    dp[j] = max(dpPrev[j], dp[j - 1]);
            dpPrev = dp;
        }

        return dp[n];
    }

    int minInsertions(string s) {
        int str_len = s.length();
        string reversed = s;
        
        reverse(reversed.begin(), reversed.end());

        return str_len - lcs(s, reversed, str_len, str_len);
    }
};