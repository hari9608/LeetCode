/*
367. Valid Perfect Square
Easy
3.7K
280
company
Amazon
company
Apple
company
LinkedIn

Given a positive integer num, return true if num is a perfect square or false otherwise.

A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

You must not use any built-in library function, such as sqrt.

 

Example 1:

Input: num = 16
Output: true
Explanation: We return true because 4 * 4 = 16 and 4 is an integer.

Example 2:

Input: num = 14
Output: false
Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.

 

Constraints:

    1 <= num <= 231 - 1

Accepted
491.6K
Submissions
1.1M
Acceptance Rate
43.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (21)
Similar Questions
Sqrt(x)
Easy
Sum of Square Numbers
Medium
Related Topics
Math
Binary Search

*/
class Solution {
    public boolean isPerfectSquare(int num) {
        if(num < 2)     return true;
        long squ = num / 2;

        while(squ * squ > num)  squ = (squ + num / squ) / 2;
        
        return (squ * squ == num);
    }
}