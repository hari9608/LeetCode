/*
560. Subarray Sum Equals K
Medium
18.3K
535
company
Amazon
company
Yandex
company
Facebook

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2

Example 2:

Input: nums = [1,2,3], k = 3
Output: 2

 

Constraints:

    1 <= nums.length <= 2 * 104
    -1000 <= nums[i] <= 1000
    -107 <= k <= 107

Accepted
978.3K
Submissions
2.2M
Acceptance Rate
43.6%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (65)
Similar Questions
Two Sum
Easy
Continuous Subarray Sum
Medium
Subarray Product Less Than K
Medium
Find Pivot Index
Easy
Subarray Sums Divisible by K
Medium
Minimum Operations to Reduce X to Zero
Medium
K Radius Subarray Averages
Medium
Maximum Sum Score of Array
Medium
Related Topics
Array
Hash Table
Prefix Sum
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int no_subarray_sum = 0;
        int subarray_sum = 0;

        map<int, int> num_sum_fre;
        
        num_sum_fre[0] = 1;

        for(int num : nums)
        {
            subarray_sum += num;   cout << subarray_sum << endl;
            no_subarray_sum += num_sum_fre[subarray_sum - k];
            num_sum_fre[subarray_sum]++;
        }

        return no_subarray_sum;
    }
};