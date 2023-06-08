/*
202. Happy Number
Easy
8.8K
1.1K
company
Apple
company
Amazon
company
Google

Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

    Starting with any positive integer, replace the number by the sum of the squares of its digits.
    Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
    Those numbers for which this process ends in 1 are happy.

Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Example 2:

Input: n = 2
Output: false

 

Constraints:

    1 <= n <= 231 - 1

Accepted
1.2M
Submissions
2.1M
Acceptance Rate
55.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (71)
Similar Questions
Linked List Cycle
Easy
Add Digits
Easy
Ugly Number
Easy
Sum of Digits of String After Convert
Easy
Minimum Addition to Make Integer Beautiful
Medium
Smallest Value After Replacing With Sum of Prime Factors
Medium
Count the Digits That Divide a Number
Easy
Related Topics
Hash Table
Math
Two Pointers
*/
class Solution {
public:
    int digitSum(int n){
        int sum = 0;
        while(n>0){
            sum += (n%10)*(n%10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do{
            slow = digitSum(slow);
            fast = digitSum(fast);
            fast = digitSum(fast);
        }while(slow != fast);
        if(slow == 1) return true;
        return false;
    }
};