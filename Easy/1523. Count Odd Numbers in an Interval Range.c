/*
1523. Count Odd Numbers in an Interval Range
Easy
2.6K
150
company
Google
company
Amazon
company
Accenture

Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).

 

Example 1:

Input: low = 3, high = 7
Output: 3
Explanation: The odd numbers between 3 and 7 are [3,5,7].

Example 2:

Input: low = 8, high = 10
Output: 1
Explanation: The odd numbers between 8 and 10 are [9].

 

Constraints:

    0 <= low <= high <= 10^9

Accepted
302.4K
Submissions
612.2K
Acceptance Rate
49.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (100)
Related Topics
Math
*/
int countOdds(int low, int high){
    int count_odds = 0;

    if(low & 1)     low++,  count_odds++;
    if(high & 1)    high--, count_odds++;

    count_odds += (high - low) / 2;

    return count_odds;
}