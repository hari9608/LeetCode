/*
2090. K Radius Subarray Averages
Medium
1.7K
78
company
Amazon
company
Facebook
Duolingo

You are given a 0-indexed array nums of n integers, and an integer k.

The k-radius average for a subarray of nums centered at some index i with the radius k is the average of all elements in nums between the indices i - k and i + k (inclusive). If there are less than k elements before or after the index i, then the k-radius average is -1.

Build and return an array avgs of length n where avgs[i] is the k-radius average for the subarray centered at index i.

The average of x elements is the sum of the x elements divided by x, using integer division. The integer division truncates toward zero, which means losing its fractional part.

    For example, the average of four elements 2, 3, 1, and 5 is (2 + 3 + 1 + 5) / 4 = 11 / 4 = 2.75, which truncates to 2.

 

Example 1:

Input: nums = [7,4,3,9,1,8,5,2,6], k = 3
Output: [-1,-1,-1,5,4,4,-1,-1,-1]
Explanation:
- avg[0], avg[1], and avg[2] are -1 because there are less than k elements before each index.
- The sum of the subarray centered at index 3 with radius 3 is: 7 + 4 + 3 + 9 + 1 + 8 + 5 = 37.
  Using integer division, avg[3] = 37 / 7 = 5.
- For the subarray centered at index 4, avg[4] = (4 + 3 + 9 + 1 + 8 + 5 + 2) / 7 = 4.
- For the subarray centered at index 5, avg[5] = (3 + 9 + 1 + 8 + 5 + 2 + 6) / 7 = 4.
- avg[6], avg[7], and avg[8] are -1 because there are less than k elements after each index.

Example 2:

Input: nums = [100000], k = 0
Output: [100000]
Explanation:
- The sum of the subarray centered at index 0 with radius 0 is: 100000.
  avg[0] = 100000 / 1 = 100000.

Example 3:

Input: nums = [8], k = 100000
Output: [-1]
Explanation: 
- avg[0] is -1 because there are less than k elements before and after index 0.

 

Constraints:

    n == nums.length
    1 <= n <= 105
    0 <= nums[i], k <= 105

Accepted
87.3K
Submissions
179K
Acceptance Rate
48.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (75)
Similar Questions
Minimum Size Subarray Sum
Medium
Moving Average from Data Stream
Easy
Subarray Sum Equals K
Medium
Maximum Average Subarray I
Easy
Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
Medium
Related Topics
Array
Sliding Window
*/
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k == 0)
            return nums;
        
        long long k_sum = 0;
        int nums_len = nums.size();
        vector<int> get_averages(nums_len, -1);
        
        if(2 * k + 1 > nums_len)
            return get_averages;

        for(int ind = 0; ind < 2 * k + 1; ind++)
            k_sum += nums[ind];

        get_averages[k] = k_sum / (2 * k + 1);

        for(int ind = 2 * k + 1; ind < nums_len; ind++)
        {
            k_sum = k_sum + nums[ind] - nums[ind - (2 * k + 1)];
            get_averages[ind - k] = k_sum / (2 * k + 1);
        }

        return get_averages;
    }
};