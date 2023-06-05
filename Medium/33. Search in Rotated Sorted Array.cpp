/*
33. Search in Rotated Sorted Array
Medium
20.8K
1.2K
company
Bloomberg
company
Amazon
company
Apple

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:

Input: nums = [1], target = 0
Output: -1

 

Constraints:

    1 <= nums.length <= 5000
    -104 <= nums[i] <= 104
    All values of nums are unique.
    nums is an ascending array that is possibly rotated.
    -104 <= target <= 104

Accepted
2M
Submissions
5.1M
Acceptance Rate
39.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (81)
Similar Questions
Search in Rotated Sorted Array II
Medium
Find Minimum in Rotated Sorted Array
Medium
Pour Water Between Buckets to Make Water Levels Equal
Medium
Related Topics
Array
Binary Search
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) 
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) 
                return mid;

            else if (nums[mid] >= nums[start]) 
                if (target >= nums[start] && target < nums[mid])    end = mid - 1;
                else                                                start = mid + 1;
            
            else
                if (target <= nums[end] && target > nums[mid])      start = mid + 1;
                else                                                end = mid - 1;
        }

        return -1;
    }
};