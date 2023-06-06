/*
2390. Removing Stars From a String
Medium
2.1K
145
company
Amazon

You are given a string s, which contains stars *.

In one operation, you can:

    Choose a star in s.
    Remove the closest non-star character to its left, as well as remove the star itself.

Return the string after all stars have been removed.

Note:

    The input will be generated such that the operation is always possible.
    It can be shown that the resulting string will always be unique.

 

Example 1:

Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".

Example 2:

Input: s = "erase*****"
Output: ""
Explanation: The entire string is removed, so we return an empty string.

 

Constraints:

    1 <= s.length <= 105
    s consists of lowercase English letters and stars *.
    The operation above can be performed on s.

Accepted
131.7K
Submissions
181.2K
Acceptance Rate
72.6%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (78)
Similar Questions
Backspace String Compare
Easy
Remove All Adjacent Duplicates In String
Easy
Related Topics
String
Stack
Simulation
*/
class Solution {
public:
    string removeStars(string s) {
        string non_star = "";

        for(int ind=0; ind<s.size(); ind++)
            if(s[ind] == '*')   
                non_star.pop_back();
            else                
                non_star.push_back(s[ind]);

        return non_star;
    }
};