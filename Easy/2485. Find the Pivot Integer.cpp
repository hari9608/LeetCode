/*
2485. Find the Pivot Integer
Easy
447
8
company
Amazon

Given a positive integer n, find the pivot integer x such that:

    The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.

Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.

 

Example 1:

Input: n = 8
Output: 6
Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.

Example 2:

Input: n = 1
Output: 1
Explanation: 1 is the pivot integer since: 1 = 1.

Example 3:

Input: n = 4
Output: -1
Explanation: It can be proved that no such integer exist.

 

Constraints:

    1 <= n <= 1000

Accepted
39K
Submissions
48.8K
Acceptance Rate
80.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (12)
Similar Questions
Bulb Switcher
Medium
Related Topics
Math
Prefix Sum
*/
class Solution {
public:
    int pivotInteger(int n) {
        vector<int> re(n+1);
        re[0] = 0;
        for(int i=1; i<=n; i++){
            re[i] = i + re[i-1];
        }
        for(int i=1; i<=n; i++){
            if((re[n]-re[i])==re[i-1]){
                return i;
            }
        }
        return -1;
    }
};