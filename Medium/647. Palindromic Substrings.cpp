/*
647. Palindromic Substrings
Medium
9.1K
191
company
Cisco
company
Goldman Sachs
company
Facebook

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

 

Constraints:

    1 <= s.length <= 1000
    s consists of lowercase English letters.

Accepted
574.8K
Submissions
856.9K
Acceptance Rate
67.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (13)
Similar Questions
Longest Palindromic Substring
Medium
Longest Palindromic Subsequence
Medium
Related Topics
String
Dynamic Programming
*/
class Solution {
public:
    int maxPalindrome(string s, int left, int right)
    {
        int len = 0;

        while(left >= 0 && right < s.size())
            if(s[left] != s[right])         break;
            else    left--,     right++,    len++;

        return len;
    }

    int countSubstrings(string s) {
        int ans = 0;
        
        for(int mid=0; mid<s.size(); mid++)
        {
            ans += maxPalindrome(s, mid, mid+1);
            ans += maxPalindrome(s, mid, mid);
        }

        return ans;
    }
};