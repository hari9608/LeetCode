/*
228. Summary Ranges
Easy
3.4K
1.8K
company
Yandex
company
Bloomberg
company
Google

You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

    "a->b" if a != b
    "a" if a == b

 

Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"

Example 2:

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"

 

Constraints:

    0 <= nums.length <= 20
    -231 <= nums[i] <= 231 - 1
    All the values of nums are unique.
    nums is sorted in ascending order.

Accepted
420.3K
Submissions
855.2K
Acceptance Rate
49.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (52)
Similar Questions
Missing Ranges
Easy
Data Stream as Disjoint Intervals
Hard
Find Maximal Uncovered Ranges
Medium
Related Topics
Array
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> summary_ranges;

        for (int i = 0; i < nums.size(); i++) 
        {
            int start = nums[i];
            while (i + 1 < nums.size() && nums[i] + 1 == nums[i + 1]) 
                i++;

            if (start != nums[i]) 
                summary_ranges.push_back(to_string(start) + "->" + to_string(nums[i]));
            else 
                summary_ranges.push_back(to_string(start));
        }

        return summary_ranges;
    }
};