/*
6. Zigzag Conversion
Medium
6K
12.1K
Zopsmart
company
Amazon
company
Apple

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

Example 3:

Input: s = "A", numRows = 1
Output: "A"

 

Constraints:

    1 <= s.length <= 1000
    s consists of English letters (lower-case and upper-case), ',' and '.'.
    1 <= numRows <= 1000

Accepted
1M
Submissions
2.2M
Acceptance Rate
44.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (143)
Related Topics
String
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;

        int col_in_section = 2 * (numRows - 1);
        int s_len = s.size();
        string zigzag = "";

        for(int curr_row=0; curr_row<numRows; curr_row++)
        {
            int col_in_between = col_in_section - 2 * curr_row;            
            for(int index = curr_row; index < s_len; index += col_in_section)
            {
                if(index < s_len)
                    zigzag += s[index];
                if(curr_row != 0 && curr_row != numRows-1 && (index + col_in_between) < s_len)
                    zigzag += s[index + col_in_between];
            }
        }

        return zigzag;
    }
};