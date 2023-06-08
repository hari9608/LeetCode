/*
70. Climbing Stairs
Easy
18.4K
575
company
Amazon
company
Yahoo
company
Adobe

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

 

Constraints:

    1 <= n <= 45

Accepted
2.4M
Submissions
4.6M
Acceptance Rate
52.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (107)
Similar Questions
Min Cost Climbing Stairs
Easy
Fibonacci Number
Easy
N-th Tribonacci Number
Easy
Minimum Rounds to Complete All Tasks
Medium
Count Number of Ways to Place Houses
Medium
Number of Ways to Reach a Position After Exactly k Steps
Medium
Count Ways To Build Good Strings
Medium
Frog Jump II
Medium
Related Topics
Math
Dynamic Programming
Memoization
*/
class Solution {
    public int climbStairs(int n) {
        int[] stairs = new int[46];
        
        stairs[0] = 0;
        stairs[1] = 1;
        stairs[2] = 2;
        stairs[3] = 3;

        for(int step=4; step<=n; step++) 
            stairs[step] = stairs[step - 1] + stairs[step - 2];

        return stairs[n];
    }
}