/*
1281. Subtract the Product and Sum of Digits of an Integer
Easy
2.2K
216
company
Google
company
Facebook
company
Uber
Given an integer number n, return the difference between the product of its digits and the sum of its digits.

 

Example 1:

Input: n = 234
Output: 15 
Explanation: 
Product of digits = 2 * 3 * 4 = 24 
Sum of digits = 2 + 3 + 4 = 9 
Result = 24 - 9 = 15

Example 2:

Input: n = 4421
Output: 21
Explanation: 
Product of digits = 4 * 4 * 2 * 1 = 32 
Sum of digits = 4 + 4 + 2 + 1 = 11 
Result = 32 - 11 = 21

 

Constraints:

    1 <= n <= 10^5

Accepted
393.1K
Submissions
454.3K
Acceptance Rate
86.5%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (33)
Related Topics
Math
*/
class Solution {
public:
    int subtractProductAndSum(int n) {
        int digit_product = 1;
        int digit_sum = 0;
        while(n > 0)
        {
            digit_product = digit_product * (n % 10);
            digit_sum = digit_sum + n % 10;
            n = n / 10;
        }

        return digit_product - digit_sum;
    }
};