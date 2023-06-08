/*
504. Base 7
Easy
689
212

Given an integer num, return a string of its base 7 representation.

 

Example 1:

Input: num = 100
Output: "202"

Example 2:

Input: num = -7
Output: "-10"

 

Constraints:

    -107 <= num <= 107

Accepted
108.5K
Submissions
223K
Acceptance Rate
48.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (3)
Related Topics
Math
*/
class Solution {
public:
    string convertToBase7(int num) {
        string str = "";
        int f=0;
        if(num < 0) {
            f = 1;
            num *= -1;
        }
        if(!num) return "0";
        while(num > 0){
            char c = num%7 + '0';
            str = c+str;
            num /= 7;
        }
        if(f) str = "-"+str;
        return str;
    }
};