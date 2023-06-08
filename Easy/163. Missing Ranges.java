/*
163. Missing Ranges
Easy
944
2.8K
company
Facebook
company
ByteDance
company
TikTok

You are given an inclusive range [lower, upper] and a sorted unique integer array nums, where all elements are within the inclusive range.

A number x is considered missing if x is in the range [lower, upper] and x is not in nums.

Return the shortest sorted list of ranges that exactly covers all the missing numbers. That is, no element of nums is included in any of the ranges, and each missing number is covered by one of the ranges.

 

 

Example 1:

Input: nums = [0,1,3,50,75], lower = 0, upper = 99
Output: [[2,2],[4,49],[51,74],[76,99]]
Explanation: The ranges are:
[2,2]
[4,49]
[51,74]
[76,99]

Example 2:

Input: nums = [-1], lower = -1, upper = -1
Output: []
Explanation: There are no missing ranges since there are no missing numbers.

 

Constraints:

    -109 <= lower <= upper <= 109
    0 <= nums.length <= 100
    lower <= nums[i] <= upper
    All the values of nums are unique.

Accepted
202.1K
Submissions
625.6K
Acceptance Rate
32.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (5)
Similar Questions
Summary Ranges
Easy
Find Maximal Uncovered Ranges
Medium
Related Topics
Array
*/
class Solution {
    public List<List<Integer>> findMissingRanges(int[] nums, int lower, int upper) {
        List<List<Integer>> missing_ranges = new ArrayList<>();
        int nums_len = nums.length - 1;

        if(nums_len == -1)
        {
            missing_ranges.add(Arrays.asList(lower, upper));
            return missing_ranges;
        }

        if(nums[0] > lower)
            missing_ranges.add(Arrays.asList(lower, nums[0] - 1));

        for(int i = 0; i < nums_len; i++)
            if(nums[i + 1] - nums[i] > 1)
                missing_ranges.add(Arrays.asList(nums[i] + 1, nums[i + 1] - 1));
    
        if(nums[nums_len] < upper)
            missing_ranges.add(Arrays.asList(nums[nums_len] + 1, upper));

        return missing_ranges;
    }
}