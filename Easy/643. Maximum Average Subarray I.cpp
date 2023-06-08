/*
643. Maximum Average Subarray I
Easy
2.5K
200
company
Facebook
company
Google

You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

Example 2:

Input: nums = [5], k = 1
Output: 5.00000

 

Constraints:

    n == nums.length
    1 <= k <= n <= 105
    -104 <= nums[i] <= 104

Accepted
219.7K
Submissions
503.2K
Acceptance Rate
43.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (4)
Similar Questions
Maximum Average Subarray II
Hard
K Radius Subarray Averages
Medium
Related Topics
Array
Sliding Window
*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;

        for(int i = 0; i < k; i++)
            sum += nums[i];

        double max_sum = sum;

        for(int i = k; i < nums.size(); i++)
        {
            sum += nums[i] - nums[i - k];
            max_sum = max(max_sum, sum); 
        }

        return max_sum / k;
    }
};