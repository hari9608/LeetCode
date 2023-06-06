/*
343. Integer Break
Medium
3.7K
367
company
Google
company
Apple
company
Facebook

Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

 

Example 1:

Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.

Example 2:

Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

 

Constraints:

    2 <= n <= 58

Accepted
233.4K
Submissions
414.7K
Acceptance Rate
56.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (15)
Similar Questions
Maximize Number of Nice Divisors
Hard
Related Topics
Math
Dynamic Programming
*/
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2 || n == 3)
            return (n - 1);

        int result = 1;

        while (n > 4)
        {
            n -= 3;
            result *= 3;
        }
        
        return (n * result);
    }
};