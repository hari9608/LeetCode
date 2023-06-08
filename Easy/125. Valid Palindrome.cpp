/*
125. Valid Palindrome
Easy
6.9K
7.1K
company
Yandex
company
Bloomberg
company
Facebook

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.

 

Constraints:

    1 <= s.length <= 2 * 105
    s consists only of printable ASCII characters.

Accepted
2M
Submissions
4.4M
Acceptance Rate
44.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (88)
Similar Questions
Palindrome Linked List
Easy
Valid Palindrome II
Easy
Maximum Product of the Length of Two Palindromic Subsequences
Medium
Find First Palindromic String in the Array
Easy
Valid Palindrome IV
Medium
Related Topics
Two Pointers
String
*/
class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";

        for(auto ch : s)    if(isalnum(ch))     str.push_back(tolower(ch));
        
        int left = 0;
        int right = str.size() - 1;

        while(left < right)     if(str[left++] != str[right--])     return false;
        
        return true;
    }
};