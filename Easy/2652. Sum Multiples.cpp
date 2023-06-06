/*
2652. Sum Multiples
Easy
226
16

Given a positive integer n, find the sum of all integers in the range [1, n] inclusive that are divisible by 3, 5, or 7.

Return an integer denoting the sum of all numbers in the given range satisfying the constraint.

 

Example 1:

Input: n = 7
Output: 21
Explanation: Numbers in the range [1, 7] that are divisible by 3, 5, or 7 are 3, 5, 6, 7. The sum of these numbers is 21.

Example 2:

Input: n = 10
Output: 40
Explanation: Numbers in the range [1, 10] that are divisible by 3, 5, or 7 are 3, 5, 6, 7, 9, 10. The sum of these numbers is 40.

Example 3:

Input: n = 9
Output: 30
Explanation: Numbers in the range [1, 9] that are divisible by 3, 5, or 7 are 3, 5, 6, 7, 9. The sum of these numbers is 30.

 

Constraints:

    1 <= n <= 103

Accepted
39.8K
Submissions
46.9K
Acceptance Rate
84.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (7)
Related Topics
Array
Math
Number Theory
*/
class Solution {
public:
    int sum_n(int n)
    {
        int n_sum = 0;

        return (n * (n + 1)) / 2;
    }

    int sumOfMultiples(int n) {
        int div_by_3 = n / 3;
        int div_by_5 = n / 5;
        int div_by_7 = n / 7;

        int div_by_3_5 = n / 15;
        int div_by_3_7 = n / 21;
        int div_by_5_7 = n / 35;

        int div_by_3_5_7 = n / 105;

        return (3 * sum_n(div_by_3)) + (5 * sum_n(div_by_5)) + (7 * sum_n(div_by_7)) - (15 * sum_n(div_by_3_5)) - (21 * sum_n(div_by_3_7)) - (35 * sum_n(div_by_5_7)) + (105 * sum_n(div_by_3_5_7));
    }
};