/*
844. Backspace String Compare
Easy
6.4K
292
company
Google
company
Microsoft
company
Booking.com

Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".

 

Constraints:

    1 <= s.length, t.length <= 200
    s and t only contain lowercase letters and '#' characters.

 

Follow up: Can you solve it in O(n) time and O(1) space?
Accepted
640.3K
Submissions
1.3M
Acceptance Rate
48.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (16)
Similar Questions
Crawler Log Folder
Easy
Removing Stars From a String
Medium
Related Topics
Two Pointers
String
Stack
Simulation
*/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string non_hash_01 = "";
        string non_hash_02 = "";
        for(int ind=0; ind<s.size(); ind++)
            if(non_hash_01.size() && s[ind] == '#')   
                non_hash_01.pop_back();
            else if(s[ind] != '#')
                non_hash_01.push_back(s[ind]);
        
        for(int ind=0; ind<t.size(); ind++)
            if(non_hash_02.size() && t[ind] == '#')   
                non_hash_02.pop_back();
            else if(t[ind] != '#')
                non_hash_02.push_back(t[ind]);
                
        return non_hash_01 == non_hash_02;
    }
};