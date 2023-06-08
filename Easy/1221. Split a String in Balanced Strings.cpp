/*
1221. Split a String in Balanced Strings
Easy
2.4K
867

Balanced strings are those that have an equal quantity of 'L' and 'R' characters.

Given a balanced string s, split it into some number of substrings such that:

    Each substring is balanced.

Return the maximum number of balanced strings you can obtain.

 

Example 1:

Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.

Example 2:

Input: s = "RLRRRLLRLL"
Output: 2
Explanation: s can be split into "RL", "RRRLLRLL", each substring contains same number of 'L' and 'R'.
Note that s cannot be split into "RL", "RR", "RL", "LR", "LL", because the 2nd and 5th substrings are not balanced.

Example 3:

Input: s = "LLLLRRRR"
Output: 1
Explanation: s can be split into "LLLLRRRR".

 

Constraints:

    2 <= s.length <= 1000
    s[i] is either 'L' or 'R'.
    s is a balanced string.

Accepted
250.6K
Submissions
293.8K
Acceptance Rate
85.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (14)
Related Topics
String
Greedy
Counting
*/
class Solution {
public:
    int balancedStringSplit(string s) {
        int maximum = 0;
        int r = 0;
        int l = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='R') r++;
            if(s[i]=='L') l++;
            if(r==l) r=0, l=0, maximum++;
        }
        return maximum;
    }
};