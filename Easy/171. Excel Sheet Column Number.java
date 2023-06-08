/*
171. Excel Sheet Column Number
Easy
4.2K
335
company
Amazon
company
Microsoft
company
Facebook

Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...

 

Example 1:

Input: columnTitle = "A"
Output: 1

Example 2:

Input: columnTitle = "AB"
Output: 28

Example 3:

Input: columnTitle = "ZY"
Output: 701

 

Constraints:

    1 <= columnTitle.length <= 7
    columnTitle consists only of uppercase English letters.
    columnTitle is in the range ["A", "FXSHRXW"].

Accepted
602.9K
Submissions
967.7K
Acceptance Rate
62.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (15)
Similar Questions
Excel Sheet Column Title
Easy
Cells in a Range on an Excel Sheet
Easy
Related Topics
Math
String
*/
class Solution {
    public int titleToNumber(String columnTitle) {
        String alpha = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int len = columnTitle.length();
        int ans = 0;
        for(int i=0; i<len; i++){
            ans *= 26;
            ans  += alpha.indexOf(columnTitle.charAt(i));
        }
        return ans;
    }
}