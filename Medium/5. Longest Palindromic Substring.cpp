/*
5. Longest Palindromic Substring
Medium
24.7K
1.5K
company
Cisco
company
Amazon
company
Microsoft

Given a string s, return the longest
palindromic
substring
in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"

 

Constraints:

    1 <= s.length <= 1000
    s consist of only digits and English letters.

Accepted
2.4M
Submissions
7.3M
Acceptance Rate
32.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (131)
Similar Questions
Shortest Palindrome
Hard
Palindrome Permutation
Easy
Palindrome Pairs
Hard
Longest Palindromic Subsequence
Medium
Palindromic Substrings
Medium
Maximum Number of Non-overlapping Palindrome Substrings
Hard
Related Topics
String
Dynamic Programming
*/

class Solution {
public:
    int maxPalindrome(string s, int left, int right)
    {
        while(left >= 0 && right < s.size() && s[left] == s[right])     left--,     right++;
        return right - left - 1;
    }

    string longestPalindrome(string s) {
        if(s.size() < 1)  return "";
        int begin = 0;
        int max_len = 0;

        for(int mid=0; mid<s.size(); mid++)
        {
            int even_len = maxPalindrome(s, mid, mid+1);
            int odd_len = maxPalindrome(s, mid, mid);
            int len = max(odd_len, even_len);

            if(len > max_len)       begin = mid - (len - 1) / 2,    max_len = len;
        }

        return s.substr(begin, max_len);
    }
};
