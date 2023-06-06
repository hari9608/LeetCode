/*
2544. Alternating Digit Sum
Easy
267
16
company
eBay

You are given a positive integer n. Each digit of n has a sign according to the following rules:

    The most significant digit is assigned a positive sign.
    Each other digit has an opposite sign to its adjacent digits.

Return the sum of all digits with their corresponding sign.

 

Example 1:

Input: n = 521
Output: 4
Explanation: (+5) + (-2) + (+1) = 4.

Example 2:

Input: n = 111
Output: 1
Explanation: (+1) + (-1) + (+1) = 1.

Example 3:

Input: n = 886996
Output: 0
Explanation: (+8) + (-8) + (+6) + (-9) + (+9) + (-6) = 0.

 

Constraints:

    1 <= n <= 109

 
Accepted
37.2K
Submissions
53.7K
Acceptance Rate
69.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (16)
Similar Questions
Add Digits
Easy
Minimum Sum of Four Digit Number After Splitting Digits
Easy
Separate the Digits in an Array
Easy
Related Topics
Math
*/

class Solution {
public:
    int alternateDigitSum(int n) {
        int ones_sum = 0;
        int twos_sum = 0;
        
        int flag = 0;

        while(n > 0)
        {
            flag = 0;
            ones_sum += n % 10;
            n /= 10;

            if(n > 0)
            {
                flag = 1;
                twos_sum += n % 10;
                n /= 10;
            }
        }

        return flag ? twos_sum - ones_sum : ones_sum - twos_sum;
    }
};