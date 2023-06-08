/*
1134. Armstrong Number
Easy
188
19
company
Amazon

Given an integer n, return true if and only if it is an Armstrong number.

The k-digit number n is an Armstrong number if and only if the kth power of each digit sums to n.

 

Example 1:

Input: n = 153
Output: true
Explanation: 153 is a 3-digit number, and 153 = 13 + 53 + 33.

Example 2:

Input: n = 123
Output: false
Explanation: 123 is a 3-digit number, and 123 != 13 + 23 + 33 = 36.

 

Constraints:

    1 <= n <= 108

Accepted
32.6K
Submissions
41.9K
Acceptance Rate
77.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (0)
Related Topics
Math
*/
class Solution {
public:
    int findArmstrong(int n, int k)
    {
        int armstrong = 0;

        while(n > 0)
        {
            armstrong += pow(n%10, k);
            n /= 10;
        }

        return armstrong;
    }

    bool isArmstrong(int n) {
        int n_length = 0;
        int temp = n;

        while(temp)     
            n_length++,     temp /= 10;

        return n == findArmstrong(n, n_length);
    }
};