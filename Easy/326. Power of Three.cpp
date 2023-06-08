/*
326. Power of Three
Easy
2.7K
250
company
Google
company
Bloomberg
company
Amazon

Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

 

Example 1:

Input: n = 27
Output: true
Explanation: 27 = 33

Example 2:

Input: n = 0
Output: false
Explanation: There is no x where 3x = 0.

Example 3:

Input: n = -1
Output: false
Explanation: There is no x where 3x = (-1).

 

Constraints:

    -231 <= n <= 231 - 1

 
Follow up: Could you solve it without loops/recursion?
Accepted
692.2K
Submissions
1.5M
Acceptance Rate
45.6%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (25)
Similar Questions
Power of Two
Easy
Power of Four
Easy
Check if Number is a Sum of Powers of Three
Medium
Related Topics
Math
Recursion
*/
class Solution {
    public boolean isPowerOfThree(int n) {
        if(n<1)
            return false;
       // n = Math.abs(n);
        double ans = Math.log10(n) / Math.log10(3);
        if(ans - (int)ans == 0)
            return true;
        return false;
    }
}