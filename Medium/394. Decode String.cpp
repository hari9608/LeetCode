/*
394. Decode String
Medium
10.6K
481
company
Bloomberg
company
Google
company
Amazon

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"

Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

 

Constraints:

    1 <= s.length <= 30
    s consists of lowercase English letters, digits, and square brackets '[]'.
    s is guaranteed to be a valid input.
    All the integers in s are in the range [1, 300].

Accepted
632.9K
Submissions
1.1M
Acceptance Rate
57.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (22)
Similar Questions
Encode String with Shortest Length
Hard
Number of Atoms
Hard
Brace Expansion
Medium
Related Topics
String
Stack
Recursion
*/

class Solution {
public:
    string decodeString(string s) {
        stack<char> stack;

        for (int i = 0; i < s.length(); i++) 
        {
            if (s[i] == ']') 
            {
                string decodedString = "";
                
                while (stack.top() != '[') 
                {
                    decodedString += stack.top();
                    stack.pop();
                }
                
                stack.pop();
                int base = 1;
                int k = 0;
                
                while (!stack.empty() && isdigit(stack.top())) 
                {
                    k = k + (stack.top() - '0') * base;
                    stack.pop();
                    base *= 10;
                }

                int currentLen = decodedString.size();
                
                while (k != 0) 
                {
                    for (int j = decodedString.size() - 1; j >= 0; j--)
                        stack.push(decodedString[j]);
                    
                    k--;
                }
            }
            
            else
                stack.push(s[i]);
            
        }

        string result;

        for (int i = stack.size() - 1; i >= 0; i--) 
        {
            result = stack.top() + result;
            stack.pop();
        }
        
        return result;
    }
};