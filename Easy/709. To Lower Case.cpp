/*
709. To Lower Case
Easy
1.6K
2.6K

Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

 

Example 1:

Input: s = "Hello"
Output: "hello"

Example 2:

Input: s = "here"
Output: "here"

Example 3:

Input: s = "LOVELY"
Output: "lovely"

 

Constraints:

    1 <= s.length <= 100
    s consists of printable ASCII characters.

Accepted
427.3K
Submissions
517.9K
Acceptance Rate
82.5%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (29)
Similar Questions
Capitalize the Title
Easy
Related Topics
String
*/
class Solution {
public:
    string toLowerCase(string s) {
        map<char, char> up_low;
        string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string lower = "abcdefghijklmnopqrstuvwxyz";
        string tolower = "";
        
        for (int i = 0; i < 26; ++i)    up_low[upper[i]] = lower[i];

        for (char x : s)    tolower.push_back(up_low[x] ? up_low[x] : x);
        
        return tolower;
    }
};