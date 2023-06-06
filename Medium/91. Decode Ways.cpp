/*
91. Decode Ways
Medium
10K
4.3K
company
TikTok
company
Amazon
company
Cisco

A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"

To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

    "AAJF" with the grouping (1 1 10 6)
    "KJF" with the grouping (11 10 6)

Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).

Example 2:

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

Example 3:

Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").

 

Constraints:

    1 <= s.length <= 100
    s contains only digits and may contain leading zero(s).

Accepted
1M
Submissions
3.1M
Acceptance Rate
32.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (68)
Similar Questions
Decode Ways II
Hard
Number of Ways to Separate Numbers
Hard
Count Number of Texts
Medium
Related Topics
String
Dynamic Programming
*/
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;

        size_t n = s.length();
        int two_back = 1;
        int one_back = 1;

        for (int i = 1; i < n; i++) 
        {
            int current = 0;

            if (s[i] != '0') 
                current = one_back;

            int two_digit = (s[i - 1] - '0') * 10 + (s[i] - '0');

            if (two_digit >= 10 and two_digit <= 26) 
                current += two_back;

            two_back = one_back;
            one_back = current;
        }

        return one_back;
    }
};