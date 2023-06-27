/*
2578. Split With Minimum Sum
Easy
249
24
company
Amazon

Given a positive integer num, split it into two non-negative integers num1 and num2 such that:

    The concatenation of num1 and num2 is a permutation of num.
        In other words, the sum of the number of occurrences of each digit in num1 and num2 is equal to the number of occurrences of that digit in num.
    num1 and num2 can contain leading zeros.

Return the minimum possible sum of num1 and num2.

Notes:

    It is guaranteed that num does not contain any leading zeros.
    The order of occurrence of the digits in num1 and num2 may differ from the order of occurrence of num.

 

Example 1:

Input: num = 4325
Output: 59
Explanation: We can split 4325 so that num1 is 24 and num2 is 35, giving a sum of 59. We can prove that 59 is indeed the minimal possible sum.

Example 2:

Input: num = 687
Output: 75
Explanation: We can split 687 so that num1 is 68 and num2 is 7, which would give an optimal sum of 75.

 

Constraints:

    10 <= num <= 109

Accepted
22.8K
Submissions
32.5K
Acceptance Rate
70.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (5)
Similar Questions
Partition Equal Subset Sum
Medium
Minimum Cost to Move Chips to The Same Position
Easy
Partition Array Into Two Arrays to Minimize Sum Difference
Hard
Related Topics
Math
Greedy
Sorting
*/

class Solution {
    public int splitNum(int num) {
        String str = num + "";
        char[] arr = str.toCharArray();

        Arrays.sort(arr);
        int n1 = 0;
        int n2 = 0;

        for(int ind = 0; ind < arr.length; ind += 2)
        {
            n1 = (n1 * 10) + (arr[ind] - '0');
    
            if(ind + 1 < arr.length)
                n2 = (n2 * 10) + (arr[ind + 1] - '0');
        }

        return n1 + n2;
    }
}