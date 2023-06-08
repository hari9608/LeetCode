/*
509. Fibonacci Number
Easy
6.8K
315
company
Amazon
company
Adobe
company
Google

The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.

Given n, calculate F(n).

 

Example 1:

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Example 3:

Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

 

Constraints:

    0 <= n <= 30

Accepted
1.4M
Submissions
1.9M
Acceptance Rate
70.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (40)
Similar Questions
Climbing Stairs
Easy
Split Array into Fibonacci Sequence
Medium
Length of Longest Fibonacci Subsequence
Medium
N-th Tribonacci Number
Easy
Related Topics
Math
Dynamic Programming
Recursion
Memoization
*/
class Solution {
public:
    int fib(int n) {
        int fibn[31];
        fibn[0] = 0;
        fibn[1] = 1;
        for(int i=2; i<=30; i++){
            fibn[i] = fibn[i-1] + fibn[i-2];
        }
        return fibn[n];
    }
};