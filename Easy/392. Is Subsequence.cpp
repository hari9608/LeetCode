/*
392. Is Subsequence
Easy
7.5K
420
company
Amazon
company
Google
company
Uber

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false

 

Constraints:

    0 <= s.length <= 100
    0 <= t.length <= 104
    s and t consist only of lowercase English letters.

 
Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?
Accepted
869.1K
Submissions
1.8M
Acceptance Rate
47.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (61)
Similar Questions
Number of Matching Subsequences
Medium
Shortest Way to Form String
Medium
Append Characters to String to Make Subsequence
Medium
Related Topics
Two Pointers
String
Dynamic Programming
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_len = s.size();
        int t_len = t.size();
        
        int s_point = 0;
        int t_point = 0;

        while(s_point < s_len && t_point < t_len)
        {
            if(s[s_point] == t[t_point])    
                s_point++;

            t_point++;
        }

        return s_point == s_len;
    }
};