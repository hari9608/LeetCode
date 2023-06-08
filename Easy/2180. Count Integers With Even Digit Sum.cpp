/*
2180. Count Integers With Even Digit Sum
Easy
503
22
MindTree

Given a positive integer num, return the number of positive integers less than or equal to num whose digit sums are even.

The digit sum of a positive integer is the sum of all its digits.

 

Example 1:

Input: num = 4
Output: 2
Explanation:
The only integers less than or equal to 4 whose digit sums are even are 2 and 4.    

Example 2:

Input: num = 30
Output: 14
Explanation:
The 14 integers less than or equal to 30 whose digit sums are even are
2, 4, 6, 8, 11, 13, 15, 17, 19, 20, 22, 24, 26, and 28.

 

Constraints:

    1 <= num <= 1000

Accepted
44K
Submissions
67K
Acceptance Rate
65.6%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (2)
Similar Questions
Sum of Numbers With Units Digit K
Medium
Sum of Digits of String After Convert
Easy
Number of Ways to Buy Pens and Pencils
Medium
Separate the Digits in an Array
Easy
Related Topics
Math
Simulation
*/
class Solution {
public:
    int digitSum(int num)
    {
        int num_sum = 0;
        while(num > 0)
            num_sum += num % 10, num /= 10;

        return !(num_sum & 1);
    }

    int countEven(int num) {
        int count_even = 0;

        for(int i=2; i<=num; i++)
            count_even += digitSum(i);

        return count_even;
    }
};