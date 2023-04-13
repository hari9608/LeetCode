/*
660. Remove 9
Hard
155
198
company
Google
company
Houzz

Start from integer 1, remove any integer that contains 9 such as 9, 19, 29...

Now, you will have a new integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 10, 11, ...].

Given an integer n, return the nth (1-indexed) integer in the new sequence.

 

Example 1:

Input: n = 9
Output: 10

Example 2:

Input: n = 10
Output: 11

Constraints:

    1 <= n <= 8 * 108

Related Topics
Math
*/
class Solution {
public:
    int newInteger(int n) {
        int new_integer = 0;
        long base = 1;
        while(n)
        {
            new_integer = new_integer + (n % 9) * base;
            base = base * 10;
            n = n / 9;
        }

        return new_integer;
    }
};