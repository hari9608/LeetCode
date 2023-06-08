/*
258. Add Digits
Easy
4.2K
1.9K
company
Google
company
Amazon
company
Apple

Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

 

Example 1:

Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.

Example 2:

Input: num = 0
Output: 0

 

Constraints:

    0 <= num <= 231 - 1

 

Follow up: Could you do it without any loop/recursion in O(1) runtime?
Accepted
653.3K
Submissions
994.4K
Acceptance Rate
65.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (37)
Similar Questions
Happy Number
Easy
Sum of Digits in the Minimum Number
Easy
Sum of Digits of String After Convert
Easy
Minimum Sum of Four Digit Number After Splitting Digits
Easy
Calculate Digit Sum of a String
Easy
Difference Between Element Sum and Digit Sum of an Array
Easy
Alternating Digit Sum
Easy
Related Topics
Math
Simulation
Number Theory
*/
class Solution {
public:
    int addDigits(int num) {
        return num == 0 ? 0 : 1 + (num - 1) % 9;
    }
};