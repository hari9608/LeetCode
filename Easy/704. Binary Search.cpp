/*
704. Binary Search
Easy
9.7K
197
company
Apple
company
Google
company
Amazon

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1

 

Constraints:

    1 <= nums.length <= 104
    -104 < nums[i], target < 104
    All the integers in nums are unique.
    nums is sorted in ascending order.

Accepted
1.8M
Submissions
3.2M
Acceptance Rate
56.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (68)
Similar Questions
Search in a Sorted Array of Unknown Size
Medium
Maximum Count of Positive Integer and Negative Integer
Easy
Related Topics
Array
Binary Search
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == target){
                return i;
            }
        }
        return -1;
    }
};