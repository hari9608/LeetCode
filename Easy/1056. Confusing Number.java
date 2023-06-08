/*
1056. Confusing Number
Easy
274
155
company
Google

A confusing number is a number that when rotated 180 degrees becomes a different number with each digit valid.

We can rotate digits of a number by 180 degrees to form new digits.

    When 0, 1, 6, 8, and 9 are rotated 180 degrees, they become 0, 1, 9, 8, and 6 respectively.
    When 2, 3, 4, 5, and 7 are rotated 180 degrees, they become invalid.

Note that after rotating a number, we can ignore leading zeros.

    For example, after rotating 8000, we have 0008 which is considered as just 8.

Given an integer n, return true if it is a confusing number, or false otherwise.

 

Example 1:

Input: n = 6
Output: true
Explanation: We get 9 after rotating 6, 9 is a valid number, and 9 != 6.

Example 2:

Input: n = 89
Output: true
Explanation: We get 68 after rotating 89, 68 is a valid number and 68 != 89.

Example 3:

Input: n = 11
Output: false
Explanation: We get 11 after rotating 11, 11 is a valid number but the value remains the same, thus 11 is not a confusing number

 

Constraints:

    0 <= n <= 109

Accepted
37.8K
Submissions
78.1K
Acceptance Rate
48.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (10)
Similar Questions
Strobogrammatic Number
Easy
Confusing Number II
Hard
Related Topics
Math
*/
class Solution {
    public boolean confusingNumber(int n) {
        Map<Integer, Integer> confusing = new HashMap<>(){{
            put(0, 0); 
            put(1, 1); 
            put(6, 9); 
            put(8, 8); 
            put(9, 6);
            }};

        int copy_n = n;
        int reverse = 0;

        while(copy_n > 0)
        {
            if(!confusing.containsKey(copy_n % 10))
                return false;

            reverse = reverse * 10 + confusing.get(copy_n % 10);
            copy_n /= 10;
        }

        return reverse != n;
    }
}