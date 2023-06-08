/*
1427. Perform String Shifts
Easy
211
5
company
Goldman Sachs

You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [directioni, amounti]:

    directioni can be 0 (for left shift) or 1 (for right shift).
    amounti is the amount by which string s is to be shifted.
    A left shift by 1 means remove the first character of s and append it to the end.
    Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.

Return the final string after all operations.

 

Example 1:

Input: s = "abc", shift = [[0,1],[1,2]]
Output: "cab"
Explanation: 
[0,1] means shift to left by 1. "abc" -> "bca"
[1,2] means shift to right by 2. "bca" -> "cab"

Example 2:

Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
Output: "efgabcd"
Explanation:  
[1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
[1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
[0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
[1,3] means shift to right by 3. "abcdefg" -> "efgabcd"

 

Constraints:

    1 <= s.length <= 100
    s only contains lower case English letters.
    1 <= shift.length <= 100
    shift[i].length == 2
    directioni is either 0 or 1.
    0 <= amounti <= 100

Accepted
75K
Submissions
138K
Acceptance Rate
54.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (3)
Related Topics
Array
Math
String
*/
class Solution {
    public String stringShift(String s, int[][] shift) {
        int left_shift = 0;
        int s_len = s.length();
        
        for(int[] move : shift)
        {
            if(move[0] == 1)    
                move[1] = -move[1];
            
            left_shift += move[1];
        }

        left_shift = Math.floorMod(left_shift, s_len);
        
        s = s.substring(left_shift) + s.substring(0, left_shift);
        
        return s;
    }
}