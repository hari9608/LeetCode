/*
319. Bulb Switcher
Medium
2.3K
2.9K
company
Amazon
company
Facebook
company
Accenture

There are n bulbs that are initially off. You first turn on all the bulbs, then you turn off every second bulb.

On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb.

Return the number of bulbs that are on after n rounds.

 

Example 1:

Input: n = 3
Output: 1
Explanation: At first, the three bulbs are [off, off, off].
After the first round, the three bulbs are [on, on, on].
After the second round, the three bulbs are [on, off, on].
After the third round, the three bulbs are [on, off, off]. 
So you should return 1 because there is only one bulb is on.

Example 2:

Input: n = 0
Output: 0

Example 3:

Input: n = 1
Output: 1

 

Constraints:

    0 <= n <= 109

Accepted
191.5K
Submissions
365.2K
Acceptance Rate
52.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (74)
Similar Questions
Bulb Switcher II
Medium
Minimum Number of K Consecutive Bit Flips
Hard
Number of Times Binary String Is Prefix-Aligned
Medium
Find the Pivot Integer
Easy
Related Topics
Math
Brainteaser
*/
int bulbSwitch(int n){
    return sqrt(n);
}