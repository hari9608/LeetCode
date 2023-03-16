/*
516. Longest Palindromic Subsequence
Medium
7K
274
company
Amazon
company
LinkedIn
company
Facebook

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".

 

Constraints:

    1 <= s.length <= 1000
    s consists only of lowercase English letters.

Accepted
324.9K
Submissions
532.7K
Acceptance Rate
61.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (14)
Similar Questions
Longest Palindromic Substring
Medium
Palindromic Substrings
Medium
Count Different Palindromic Subsequences
Hard
Longest Common Subsequence
Medium
Longest Palindromic Subsequence II
Medium
Maximize Palindrome Length From Subsequences
Hard
Maximum Product of the Length of Two Palindromic Subsequences
Medium
Related Topics
String
Dynamic Programming

*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int s_len;
        s_len = s.size();
        int lps[s_len][s_len];
        for(int ind=0; ind<s_len; ind++) for(int ind1=0; ind1<s_len; ind1++) lps[ind][ind1] = 0;
        for(int row=s_len-1; row>=0; row--)
            for(int col=row; col<s_len; col++)
                if(row == col) lps[row][col] = 1;
                else if(s[row] == s[col])    lps[row][col] = lps[row+1][col-1] + 2;
                else lps[row][col] = max(lps[row+1][col], lps[row][col-1]);
        return lps[0][s_len-1];
    }
};