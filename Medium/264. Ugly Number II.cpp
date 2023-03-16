/*
264. Ugly Number II
Medium
5.2K
257
company
Bloomberg
company
Adobe
company
Microsoft

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

 

Constraints:

    1 <= n <= 1690

Accepted
301.4K
Submissions
652.6K
Acceptance Rate
46.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (15)
Similar Questions
Merge k Sorted Lists
Hard
Count Primes
Medium
Ugly Number
Easy
Perfect Squares
Medium
Super Ugly Number
Medium
Ugly Number III
Medium
Related Topics
Hash Table
Math
Dynamic Programming
Heap (Priority Queue)

*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly_number;
        ugly_number.push_back(1);
        int two = 0;
        int the = 0;
        int fiv = 0;

        while(--n)
        {
            ugly_number.push_back(min(ugly_number[two] * 2, min(ugly_number[the] * 3, ugly_number[fiv] * 5)));
            if(ugly_number.back() == ugly_number[two] * 2)      two++;
            if(ugly_number.back() == ugly_number[the] * 3)      the++;
            if(ugly_number.back() == ugly_number[fiv] * 5)      fiv++;
        }

        return ugly_number.back();
    }
};