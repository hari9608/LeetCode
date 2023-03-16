/*
556. Next Greater Element III
Medium
3.1K
403
company
Amazon
company
Google
company
DoorDash

Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

 

Example 1:

Input: n = 12
Output: 21

Example 2:

Input: n = 21
Output: -1

 

Constraints:

    1 <= n <= 231 - 1

Accepted
124.3K
Submissions
365.2K
Acceptance Rate
34.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (8)
Similar Questions
Next Greater Element I
Easy
Next Greater Element II
Medium
Next Palindrome Using Same Digits
Hard
Related Topics
Math
Two Pointers
String

*/
class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        next_permutation(begin(str), end(str));
        int res = stoll(str);
        return (res > INT_MAX || res <= n ? -1 : res);
    }
};
