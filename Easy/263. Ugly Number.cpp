/*
263. Ugly Number
Easy
2.9K
1.5K
company
Bloomberg
company
Facebook
company
Amazon

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return true if n is an ugly number.

 

Example 1:

Input: n = 6
Output: true
Explanation: 6 = 2 × 3

Example 2:

Input: n = 1
Output: true
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

Example 3:

Input: n = 14
Output: false
Explanation: 14 is not ugly since it includes the prime factor 7.

 

Constraints:

    -231 <= n <= 231 - 1

Accepted
430.3K
Submissions
1M
Acceptance Rate
42.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (35)
Similar Questions
Happy Number
Easy
Count Primes
Medium
Ugly Number II
Medium
Related Topics
Math
*/
class Solution {
public:
    bool isUgly(int n) {
        if(n<=0) return false;
        while(n%5==0)     n /= 5;
        while(n%3 == 0)   n /= 3;
        while(n%2 == 0)   n /= 2;
        return n==1?true:false;
    }
};