/*
2348. Number of Zero-Filled Subarrays
Medium
2K
67
company
Google

Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,3,0,0,2,0,0,4]
Output: 6
Explanation: 
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.

Example 2:

Input: nums = [0,0,0,2,0,0]
Output: 9
Explanation:
There are 5 occurrences of [0] as a subarray.
There are 3 occurrences of [0,0] as a subarray.
There is 1 occurrence of [0,0,0] as a subarray.
There is no occurrence of a subarray with a size more than 3 filled with 0. Therefore, we return 9.

Example 3:

Input: nums = [2,10,2019]
Output: 0
Explanation: There is no subarray filled with 0. Therefore, we return 0.

 

Constraints:

    1 <= nums.length <= 105
    -109 <= nums[i] <= 109

Accepted
107.3K
Submissions
160.7K
Acceptance Rate
66.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (43)
Similar Questions
Arithmetic Slices
Medium
Number of Smooth Descent Periods of a Stock
Medium
Length of the Longest Alphabetical Continuous Substring
Medium
Find Consecutive Integers from a Data Stream
Medium
Related Topics
Array
Math
*/
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long zero_filled_subarray = 0;
        long long contiguous_zeros = 0;

        for(auto num : nums)
        {
            if(!num)    contiguous_zeros++;
            else
            {
                zero_filled_subarray += (contiguous_zeros * (contiguous_zeros + 1) / 2);
                contiguous_zeros = 0;
            }
        }
        zero_filled_subarray += (contiguous_zeros * (contiguous_zeros + 1) / 2);

        return zero_filled_subarray;
    }
};
/*
 0 0 0 0 - 4 + 3 + 2 + 1
no of zero      size
    0             0
    1             1
    2             3
    3             6
    4             10
    5             15
*/