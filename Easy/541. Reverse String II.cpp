/*
541. Reverse String II
Easy
1.6K
3.2K
company
Apple
company
Adobe
company
Microsoft

Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.

 

Example 1:

Input: s = "abcdefg", k = 2
Output: "bacdfeg"

Example 2:

Input: s = "abcd", k = 2
Output: "bacd"

 

Constraints:

    1 <= s.length <= 104
    s consists of only lowercase English letters.
    1 <= k <= 104

Accepted
199.2K
Submissions
395K
Acceptance Rate
50.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (19)
Similar Questions
Reverse String
Easy
Reverse Words in a String III
Easy
Related Topics
Two Pointers
String
*/
class Solution {
public:
    string reverseStr(string s, int k) {
        stack<char> storage;
        int s_len = s.size();
        string reverse_words;

        int i = 0;
        while( i < s_len)
        {
            int tk = k;
            while(i < s_len && tk--)
                storage.push(s[i++]);

            while(!storage.empty())
            {
                reverse_words += storage.top();
                storage.pop();
            }
                
            tk = k;
            while(i < s_len && tk--)
                reverse_words += s[i++];
        }

        return reverse_words;
    }
};