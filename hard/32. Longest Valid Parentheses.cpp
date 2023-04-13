/*
32. Longest Valid Parentheses
Hard
10.8K
340
company
Amazon
company
Microsoft
Oracle

Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses
substring

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:

Input: s = ""
Output: 0

 

Constraints:

    0 <= s.length <= 3 * 104
    s[i] is '(', or ')'.

Similar Questions
Valid Parentheses

Related Topics
String
Dynamic Programming
Stack
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0;
        int right = 0;
        int longest_valid_parentheses = 0;

        for(auto c : s)
        {
            if(c == '(')    left++;
            else            right++;
            if(right == left)               longest_valid_parentheses = max(longest_valid_parentheses, 2*right);
            else if(right >= left)          left = 0, right = 0;
        }

        left = 0;
        right = 0;
        reverse(s.begin(), s.end());
        
        for(auto c : s)
        {
            if(c == '(')    left++;
            else            right++;
            if(right == left)               longest_valid_parentheses = max(longest_valid_parentheses, left*2);
            else if(right <= left)          left = 0, right = 0;
        }
        
        return longest_valid_parentheses;
    }
};