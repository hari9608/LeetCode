/*
633. Sum of Square Numbers
Medium
2.2K
521
company
Amazon
company
Bloomberg
company
Apple

Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

 

Example 1:

Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:

Input: c = 3
Output: false

 

Constraints:

    0 <= c <= 231 - 1

Accepted
172.8K
Submissions
503.6K
Acceptance Rate
34.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (9)
Similar Questions
Valid Perfect Square
Easy
Related Topics
Math
Two Pointers
Binary Search
*/
class Solution {
public:
    bool findSquare(long start, long end, long num)
    {
        if(start > end)         return false;

        long mid = start + (end - start) / 2;

        if(mid * mid == num)    return true;
        if(mid * mid > num)     return findSquare(start, mid - 1, num);

        return findSquare(mid + 1, end, num);
    }

    bool judgeSquareSum(int c) {
        for(long a = 0; a * a <= c; a++)
        {
            int b = c - (int)(a * a);
            if(findSquare(0, b, b))
                return true;
        }

        return false;
    }
};