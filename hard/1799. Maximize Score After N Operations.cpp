/*
1799. Maximize Score After N Operations
Hard
1.5K
104
company
Bloomberg
company
Amazon
company
Sprinklr

You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.

In the ith operation (1-indexed), you will:

    Choose two elements, x and y.
    Receive a score of i * gcd(x, y).
    Remove x and y from nums.

Return the maximum score you can receive after performing n operations.

The function gcd(x, y) is the greatest common divisor of x and y.

 

Example 1:

Input: nums = [1,2]
Output: 1
Explanation: The optimal choice of operations is:
(1 * gcd(1, 2)) = 1

Example 2:

Input: nums = [3,4,6,8]
Output: 11
Explanation: The optimal choice of operations is:
(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11

Example 3:

Input: nums = [1,2,3,4,5,6]
Output: 14
Explanation: The optimal choice of operations is:
(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14

 

Constraints:

    1 <= n <= 7
    nums.length == 2 * n
    1 <= nums[i] <= 106

Accepted
53.4K
Submissions
91.1K
Acceptance Rate
58.6%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (48)
Related Topics
Array
Math
Dynamic Programming
Backtracking
Bit Manipulation
Number Theory
Bitmask
*/
class Solution { 
public:
    int gcdMemo[14][14] = {};
    int memo[1 << 14] = {};
    int m;
    int n;

    int maxScore(vector<int>& nums) {
        m = nums.size();
        n = m / 2;

        return dp(nums, 1, 0);
    }

    int dp(vector<int>& nums, int op, int mask) {
        if (op > n) 
            return 0;

        if (memo[mask] != 0) 
            return memo[mask];

        for (int i = 0; i < m; ++i) 
        {
            if ((mask >> i) & 1)        continue;

            for (int j = i + 1; j < m; ++j) 
            {
                if ((mask >> j) & 1)    continue;
                
                int newMask = (1 << i) | (1 << j) | mask;
                int score = op * gcd(nums, i, j) + dp(nums, op + 1, newMask);
                memo[mask] = max(memo[mask], score);
            }
        }

        return memo[mask];
    }

    int gcd(vector<int>& nums, int i, int j) {
        if (gcdMemo[i][j] != 0) 
            return gcdMemo[i][j];

        return gcdMemo[i][j] = __gcd(nums[i], nums[j]);
    }
};