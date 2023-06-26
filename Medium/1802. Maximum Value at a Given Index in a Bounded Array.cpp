/*
1802. Maximum Value at a Given Index in a Bounded Array
Medium
2.3K
360
company
Apple
company
Adobe
company
Bloomberg

You are given three positive integers: n, index, and maxSum. You want to construct an array nums (0-indexed) that satisfies the following conditions:

    nums.length == n
    nums[i] is a positive integer where 0 <= i < n.
    abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
    The sum of all the elements of nums does not exceed maxSum.
    nums[index] is maximized.

Return nums[index] of the constructed array.

Note that abs(x) equals x if x >= 0, and -x otherwise.

 

Example 1:

Input: n = 4, index = 2,  maxSum = 6
Output: 2
Explanation: nums = [1,2,2,1] is one array that satisfies all the conditions.
There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum nums[2].

Example 2:

Input: n = 6, index = 1,  maxSum = 10
Output: 3

 

Constraints:

    1 <= n <= maxSum <= 109
    0 <= index < n

Accepted
60.4K
Submissions
148.2K
Acceptance Rate
40.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (86)
Related Topics
Binary Search
Greedy
*/
class Solution {
public:
    bool getSum(int n, int ind, int maxSum, int mid) 
    {
        for (int diff = 1; maxSum >= 0 && diff < mid && ind + diff < n; diff++)
            maxSum -= mid - diff;
    
        for (int diff = 1; maxSum >= 0 && diff < mid && ind - diff >= 0; diff++)
            maxSum -= mid - diff;

        return maxSum >= 0;
    }

    int maxValue(int n, int index, int maxSum) {
        int left = 0;
        int right = maxSum;

        while (left < right) 
        {
            int mid = (left + right + 1) / 2;
            
            if (getSum(n, index, maxSum - n - mid, mid)) 
                left = mid;
            else 
                right = mid - 1;
        }
        
        return left + 1;
    }
};