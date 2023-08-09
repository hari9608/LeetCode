/*
808. Soup Servings
Medium
892
2.4K
company
Google
company
Apple
company
Amazon

There are two types of soup: type A and type B. Initially, we have n ml of each type of soup. There are four kinds of operations:

    Serve 100 ml of soup A and 0 ml of soup B,
    Serve 75 ml of soup A and 25 ml of soup B,
    Serve 50 ml of soup A and 50 ml of soup B, and
    Serve 25 ml of soup A and 75 ml of soup B.

When we serve some soup, we give it to someone, and we no longer have it. Each turn, we will choose from the four operations with an equal probability 0.25. If the remaining volume of soup is not enough to complete the operation, we will serve as much as possible. We stop once we no longer have some quantity of both types of soup.

Note that we do not have an operation where all 100 ml's of soup B are used first.

Return the probability that soup A will be empty first, plus half the probability that A and B become empty at the same time. Answers within 10-5 of the actual answer will be accepted.

 

Example 1:

Input: n = 50
Output: 0.62500
Explanation: If we choose the first two operations, A will become empty first.
For the third operation, A and B will become empty at the same time.
For the fourth operation, B will become empty first.
So the total probability of A becoming empty first plus half the probability that A and B become empty at the same time, is 0.25 * (1 + 1 + 0.5 + 0) = 0.625.

Example 2:

Input: n = 100
Output: 0.71875

 

Constraints:

    0 <= n <= 109

Accepted
58.5K
Submissions
105.3K
Acceptance Rate
55.5%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (64)
Related Topics
Math
Dynamic Programming
Probability and Statistics
*/

class Solution {
public:
    map<pair<int, int>, double> dp;
    
    double solve(int a, int b) 
    {
        if(a <= 0 && b <= 0)
            return 0.5;
        
        if(a <= 0)
            return 1;
        
        if(b <= 0)
            return 0;

        if(dp.find({a,b}) != dp.end())
            return dp[{a, b}];
        
        return dp[{a, b}] = 0.25 * (solve(a - 100, b) + solve(a - 75, b - 25) + solve(a - 50, b - 50) + solve(a - 25, b - 75));
    }

    double soupServings(int n) {
        return n > 4750 ? 1 : solve(n, n);
    }
};