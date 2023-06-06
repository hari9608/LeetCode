/*
918. Maximum Sum Circular Subarray
Medium
5.8K
253
company
Amazon
company
Google
company
Adobe

Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.

Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.

Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.

 

Constraints:

    n == nums.length
    1 <= n <= 3 * 104
    -3 * 104 <= nums[i] <= 3 * 104

Accepted
211K
Submissions
488.9K
Acceptance Rate
43.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (50)
Related Topics
Array
Divide and Conquer
Dynamic Programming
Queue
Monotonic Queue
*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int cur_max = 0;
        int cur_min = 0;
        int max_sum = nums[0];
        int min_sum = nums[0];
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            cur_max = max(cur_max, 0) + nums[i];
            max_sum = max(cur_max, max_sum);
            cur_min = min(cur_min, 0) + nums[i];
            min_sum = min(cur_min, min_sum);
            sum += nums[i];
        }

        return sum == min_sum ? max_sum : max(max_sum, sum - min_sum);
    }
};