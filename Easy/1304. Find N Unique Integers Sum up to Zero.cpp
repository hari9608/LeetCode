/*
1304. Find N Unique Integers Sum up to Zero
Easy
1.7K
560
company
Microsoft
company
Tesla
company
Adobe

Given an integer n, return any array containing n unique integers such that they add up to 0.

 

Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].

Example 2:

Input: n = 3
Output: [-1,0,1]

Example 3:

Input: n = 1
Output: [0]

 

Constraints:

    1 <= n <= 1000

Accepted
186.8K
Submissions
243.1K
Acceptance Rate
76.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (2)
Related Topics
Array
Math
*/
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> sum_zero;
        if(n & 1)   sum_zero.push_back(0);
        n = n / 2;
        while(n--)
        {
            sum_zero.push_back(-n-1);
            sum_zero.push_back(n+1);
        }

        return sum_zero;
    }
};