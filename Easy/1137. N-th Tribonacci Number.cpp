/*
1137. N-th Tribonacci Number
Easy
3.6K
158
company
Amazon
company
Adobe
company
Apple

The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

 

Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4

Example 2:

Input: n = 25
Output: 1389537

 

Constraints:

    0 <= n <= 37
    The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.

Accepted
495.7K
Submissions
778.8K
Acceptance Rate
63.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (52)
Similar Questions
Climbing Stairs
Easy
Fibonacci Number
Easy
Related Topics
Math
Dynamic Programming
Memoization
*/
class Solution {
public:
    int tribonacci(int n) {
        // t n+3 = t n + t n+1 + t n+2
        // n == n-3
        // t n-3+3 = t n-3 + t n-3+1 + t n-3+2
        // t(n) = t(n-3) + t(n-2) + t(n-1)

        int TriFib[38];
        TriFib[0] = 0;
        TriFib[1] = 1;
        TriFib[2] = 1;
        for(int n1=3; n1<=37; n1++){
            TriFib[n1] = TriFib[n1-3] + TriFib[n1-2] + TriFib[n1-1];
        }
        return TriFib[n];
    }
};