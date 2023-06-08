/*
1180. Count Substrings with Only One Distinct Letter
Easy
328
49
Virtu Financial

Given a string s, return the number of substrings that have only one distinct letter.

 

Example 1:

Input: s = "aaaba"
Output: 8
Explanation: The substrings with one distinct letter are "aaa", "aa", "a", "b".
"aaa" occurs 1 time.
"aa" occurs 2 times.
"a" occurs 4 times.
"b" occurs 1 time.
So the answer is 1 + 2 + 4 + 1 = 8.

Example 2:

Input: s = "aaaaaaaaaa"
Output: 55

 

Constraints:

    1 <= s.length <= 1000
    s[i] consists of only lowercase English letters.

Accepted
24.1K
Submissions
30.5K
Acceptance Rate
79.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (1)
Related Topics
Math
String
*/
class Solution {
public:
    int countLetters(string s) {
        int count_letters = 1;
        int curr_len = 1;
        for(int i=1; i<s.size(); i++)
        {
            if(s[i] == s[i-1])      curr_len++;
            else                    curr_len = 1;
            count_letters += curr_len;
        }

        return count_letters;
    }
};