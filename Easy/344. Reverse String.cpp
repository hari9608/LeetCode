/*
344. Reverse String
Easy
7.4K
1.1K
company
Adobe
company
Apple
company
Amazon

Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

 

Constraints:

    1 <= s.length <= 105
    s[i] is a printable ascii character.

Accepted
2.1M
Submissions
2.7M
Acceptance Rate
76.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (83)
Similar Questions
Reverse Vowels of a String
Easy
Reverse String II
Easy
Related Topics
Two Pointers
String
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        int sta = 0;
        int end = s.size() - 1;
        
        while(sta < end)
            swap(s[sta++], s[end--]);
    }
};