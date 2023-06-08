/*
205. Isomorphic Strings
Easy
6.8K
1.5K
company
Microsoft
company
LinkedIn
company
Amazon

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true

Example 2:

Input: s = "foo", t = "bar"
Output: false

Example 3:

Input: s = "paper", t = "title"
Output: true

 

Constraints:

    1 <= s.length <= 5 * 104
    t.length == s.length
    s and t consist of any valid ascii character.

Accepted
905.8K
Submissions
2.1M
Acceptance Rate
43.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (91)
Similar Questions
Word Pattern
Easy
Related Topics
Hash Table
String
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> isomorphic_s(256, -1);
        vector<int> isomorphic_t(256, -1);
                
        for(int i=0; i<s.size(); i++)
        {
            char si = s[i];
            char ti = t[i];

            if(isomorphic_s[si] == -1 && isomorphic_t[ti] == -1)
            {
                isomorphic_s[s[i]] = ti;
                isomorphic_t[t[i]] = si;
            }
            else if(!(isomorphic_s[si] == ti && isomorphic_t[ti] == si))
            {
                return false;
            }
        }

        return true;
    }
};