/*
34. Find First and Last Position of Element in Sorted Array
Medium
16.6K
394
company
Amazon
company
Facebook
company
Bloomberg

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

 

Constraints:

    0 <= nums.length <= 105
    -109 <= nums[i] <= 109
    nums is a non-decreasing array.
    -109 <= target <= 109

Accepted
1.5M
Submissions
3.6M
Acceptance Rate
41.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (59)
Similar Questions
First Bad Version
Easy
Plates Between Candles
Medium
Find Target Indices After Sorting Array
Easy
Related Topics
Array
Binary Search
*/

class Solution {
    public int[] searchRange(int[] nums, int target) {
        
        int start = this.findBound(nums, target, true);
        
        if (start == -1)    return new int[]{-1, -1};
        
        int end = this.findBound(nums, target, false);
        
        return new int[]{start, end};
    }
    
    private int findBound(int[] nums, int target, boolean isFirst) {
        int N = nums.length;
        int begin = 0;
        int end = N - 1;
        
        while (begin <= end) 
        {
            int mid = (begin + end) / 2;
            
            if (nums[mid] == target)
                if (isFirst)
                    if (mid == begin || nums[mid - 1] != target)    return mid;
                    else                                            end = mid - 1;
                else
                    if (mid == end || nums[mid + 1] != target)      return mid;
                    else                                            begin = mid + 1;
            else if (nums[mid] > target)        end = mid - 1;
            else                                begin = mid + 1;
        }
        
        return -1;
    }
}