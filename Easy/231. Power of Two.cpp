/*
231. Power of Two
Easy
5.3K
364
company
Adobe
company
Amazon
company
Apple

Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1

Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16

Example 3:

Input: n = 3
Output: false

 

Constraints:

    -231 <= n <= 231 - 1

 
Follow up: Could you solve it without loops/recursion?
Accepted
905.5K
Submissions
2M
Acceptance Rate
46.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (65)
Similar Questions
Number of 1 Bits
Easy
Power of Three
Easy
Power of Four
Easy
Related Topics
Math
Bit Manipulation
Recursion
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && !(n & (n-1));
    }
};