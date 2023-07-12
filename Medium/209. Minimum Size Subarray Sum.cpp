/*
209. Minimum Size Subarray Sum
Medium
10.6K
296
company
Apple
company
Citadel
company
Amazon

Given an array of positive integers nums and a positive integer target, return the minimal length of a
subarray
whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

 

Constraints:

    1 <= target <= 109
    1 <= nums.length <= 105
    1 <= nums[i] <= 104

 
Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).
Accepted
766K
Submissions
1.7M
Acceptance Rate
46.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (80)
Similar Questions
Minimum Window Substring
Hard
Maximum Size Subarray Sum Equals k
Medium
Maximum Length of Repeated Subarray
Medium
Minimum Operations to Reduce X to Zero
Medium
K Radius Subarray Averages
Medium
Maximum Product After K Increments
Medium
Related Topics
Array
Binary Search
Sliding Window
Prefix Sum
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int window_sum = 0;
        int min_sub_array_len = INT_MAX;

        for(right = 0; right < nums.size(); right++) 
        {
            window_sum += nums[right];

            while (window_sum >= target) 
            {
                min_sub_array_len = min(min_sub_array_len, right - left + 1);
                window_sum -= nums[left];
                left++;
            }
        }

        return min_sub_array_len == INT_MAX ? 0 : min_sub_array_len;
    }
};