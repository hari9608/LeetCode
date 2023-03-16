/*
1143. Longest Common Subsequence
Medium
10.4K
124
company
Amazon
company
DoorDash
company
Apple

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

    For example, "ace" is a subsequence of "abcde".

A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

 

Constraints:

    1 <= text1.length, text2.length <= 1000
    text1 and text2 consist of only lowercase English characters.

Accepted
663K
Submissions
1.1M
Acceptance Rate
58.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (41)
Similar Questions
Longest Palindromic Subsequence
Medium
Delete Operation for Two Strings
Medium
Shortest Common Supersequence
Hard
Maximize Number of Subsequences in a String
Medium
Subsequence With the Minimum Score
Hard
Related Topics
String
Dynamic Programming

*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int text1_len;
        int text2_len;
        text1_len = text1.size();
        text2_len = text2.size();
        int lcs[text1_len+1][text2_len+1];
        for(int t1=0; t1<=text1_len; t1++)
            for(int t2=0; t2<=text2_len; t2++)
                if(!t1 || !t2) lcs[t1][t2] = 0;
                else if(text1[t1-1] == text2[t2-1]) lcs[t1][t2] = 1 + lcs[t1-1][t2-1];
                else lcs[t1][t2] = max(lcs[t1-1][t2], lcs[t1][t2-1]);
        return lcs[text1_len][text2_len];
    }
};
