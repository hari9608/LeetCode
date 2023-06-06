/*
2330. Valid Palindrome IV
Medium
58
15
company
Amazon

You are given a 0-indexed string s consisting of only lowercase English letters. In one operation, you can change any character of s to any other character.

Return true if you can make s a palindrome after performing exactly one or two operations, or return false otherwise.

 

Example 1:

Input: s = "abcdba"
Output: true
Explanation: One way to make s a palindrome using 1 operation is:
- Change s[2] to 'd'. Now, s = "abddba".
One operation could be performed to make s a palindrome so return true.

Example 2:

Input: s = "aa"
Output: true
Explanation: One way to make s a palindrome using 2 operations is:
- Change s[0] to 'b'. Now, s = "ba".
- Change s[1] to 'b'. Now, s = "bb".
Two operations could be performed to make s a palindrome so return true.

Example 3:

Input: s = "abcdef"
Output: false
Explanation: It is not possible to make s a palindrome using one or two operations so return false.

 

Constraints:

    1 <= s.length <= 105
    s consists only of lowercase English letters.

Accepted
3.2K
Submissions
4.2K
Acceptance Rate
76.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (1)
Similar Questions
Valid Palindrome
Easy
Valid Palindrome II
Easy
Valid Palindrome III
Hard
Related Topics
Two Pointers
String
*/
class Solution {
public:
    bool makePalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        int count = 0;

        while(left < right)
        {
            if(s[left] != s[right])     count++;    left++;     right--;     
        }

        return count < 3; 
    }
};