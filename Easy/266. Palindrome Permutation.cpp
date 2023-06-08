/*
266. Palindrome Permutation
Easy
983
67
company
Facebook
company
Google
company
Microsoft

Given a string s, return true if a permutation of the string could form a
palindrome
and false otherwise.

 

Example 1:

Input: s = "code"
Output: false

Example 2:

Input: s = "aab"
Output: true

Example 3:

Input: s = "carerac"
Output: true

 

Constraints:

    1 <= s.length <= 5000
    s consists of only lowercase English letters.

Accepted
182.4K
Submissions
275.8K
Acceptance Rate
66.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (2)
Similar Questions
Longest Palindromic Substring
Medium
Valid Anagram
Easy
Palindrome Permutation II
Medium
Longest Palindrome
Easy
Related Topics
Hash Table
String
Bit Manipulation
*/
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int arr[26] = {0};
        int flag = 0;

        for(char c:s)       arr[c-'a']++;
            
        for(int i=0; i<26; i++)
            if(!flag && (arr[i] & 1))  flag = 1;
            else if(flag && (arr[i] & 1)) return false;
        
        return true;
    }
};