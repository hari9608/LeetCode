/*
35. Search Insert Position
Easy
13.5K
587
company
Amazon
company
Google
company
Apple

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4

 

Constraints:

    1 <= nums.length <= 104
    -104 <= nums[i] <= 104
    nums contains distinct values sorted in ascending order.
    -104 <= target <= 104

Accepted
2.2M
Submissions
5.1M
Acceptance Rate
43.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (125)
Similar Questions
First Bad Version
Easy
Related Topics
Array
Binary Search
*/
class Solution {
    public int searchInsert(int[] nums, int target) {
        
        for(int i=0; i<nums.length; i++)
            if(nums[i]==target)         return i;
            else if(nums[i] > target)   return i;
        
        return nums.length;
    }
}