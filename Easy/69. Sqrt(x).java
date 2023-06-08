/*
69. Sqrt(x)
Easy
6.5K
4.1K
company
Amazon
company
Bloomberg
company
Microsoft

Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

    For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.

 

Constraints:

    0 <= x <= 231 - 1

Accepted
1.5M
Submissions
4M
Acceptance Rate
37.6%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (94)
Similar Questions
Pow(x, n)
Medium
Valid Perfect Square
Easy
Related Topics
Math
Binary Search
*/
class Solution {
    public int mySqrt(int x) {
        if(x < 2)   return x;
        double min = x;
        double max = (min + x / min) / 2.0;

        while(Math.abs(min - max) >= 1)
        {
            min = max;
            max = (min + x / min) / 2.0;
        }

        return (int)max;
    }
}