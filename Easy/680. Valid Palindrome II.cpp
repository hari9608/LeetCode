/*
680. Valid Palindrome II
Easy
7.3K
370
company
Yandex
company
Facebook
company
TikTok

Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true

Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.

Example 3:

Input: s = "abc"
Output: false

 

Constraints:

    1 <= s.length <= 105
    s consists of lowercase English letters.

Accepted
598.5K
Submissions
1.5M
Acceptance Rate
39.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (21)
Similar Questions
Valid Palindrome
Easy
Valid Palindrome III
Hard
Valid Palindrome IV
Medium
Related Topics
Two Pointers
String
Greedy
*/
class Solution {
public:
    bool isPalindrome(string str, int left, int right)
    {
        while(left < right)
            if(str[left] == str[right])     
                left++,     right--;
            else    
                return false;

        return true;
    }

    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right)
            if(s[left] == s[right])     
                left++,     right--;
            else    
                return (isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1));

        return true;
    }
};