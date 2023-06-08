/*
292. Nim Game
Easy
1.5K
2.5K
company
Google
company
Adobe
company
Microsoft

You are playing the following Nim Game with your friend:

    Initially, there is a heap of stones on the table.
    You and your friend will alternate taking turns, and you go first.
    On each turn, the person whose turn it is will remove 1 to 3 stones from the heap.
    The one who removes the last stone is the winner.

Given n, the number of stones in the heap, return true if you can win the game assuming both you and your friend play optimally, otherwise return false.

 

Example 1:

Input: n = 4
Output: false
Explanation: These are the possible outcomes:
1. You remove 1 stone. Your friend removes 3 stones, including the last stone. Your friend wins.
2. You remove 2 stones. Your friend removes 2 stones, including the last stone. Your friend wins.
3. You remove 3 stones. Your friend removes the last stone. Your friend wins.
In all outcomes, your friend wins.

Example 2:

Input: n = 1
Output: true

Example 3:

Input: n = 2
Output: true

 

Constraints:

    1 <= n <= 231 - 1

Accepted
326K
Submissions
580.4K
Acceptance Rate
56.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (36)
Similar Questions
Flip Game II
Medium
Related Topics
Math
Brainteaser
Game Theory
*/
class Solution {
public:
    bool canWinNim(int n) {
        return n%4;
    }
};