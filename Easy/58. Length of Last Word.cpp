/*
58. Length of Last Word
Easy
3.3K
176
company
Apple
company
Amazon
company
Adobe

Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal
substring
consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.

 

Constraints:

    1 <= s.length <= 104
    s consists of only English letters and spaces ' '.
    There will be at least one word in s.

Accepted
1.2M
Submissions
2.6M
Acceptance Rate
43.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (81)
Related Topics
String
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ind = s.size() - 1;
        while(s[ind] == ' ')                ind--;
        int last_word_last_index = ind;
        while(ind >= 0 && s[ind] != ' ')    ind--;
        return last_word_last_index - ind;
    }
};