/*
415. Add Strings
Easy
4.5K
659
company
Apple
company
Facebook
company
Adobe

Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

 

Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"

Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"

Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"

 

Constraints:

    1 <= num1.length, num2.length <= 104
    num1 and num2 consist of only digits.
    num1 and num2 don't have any leading zeros except for the zero itself.

Accepted
573.1K
Submissions
1.1M
Acceptance Rate
52.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (14)
Similar Questions
Add Two Numbers
Medium
Multiply Strings
Medium
Add to Array-Form of Integer
Easy
Related Topics
Math
String
Simulation
*/
class Solution {
    public String addStrings(String num1, String num2) {
        String add_strings = "";
        int num1_ind = num1.length() - 1;
        int num2_ind = num2.length() - 1;
        int carry = 0;
        
        while(num1_ind >= 0 || num2_ind >= 0)
        {
            int n1 = num1_ind >= 0 ? num1.charAt(num1_ind) - '0' : 0;
            int n2 = num2_ind >= 0 ? num2.charAt(num2_ind) - '0' : 0;
            int sum = (n1 + n2 + carry) % 10;

            carry = (n1 + n2 + carry) / 10;
            add_strings = sum + add_strings;
            num1_ind--;
            num2_ind--;
        }

        if(carry != 0)  
            return carry + add_strings;

        return add_strings;
    }
}