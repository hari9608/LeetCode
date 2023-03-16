/*
540. Single Element in a Sorted Array
Medium
8.9K
132
company
Amazon
company
Adobe
company
Google

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10

 

Constraints:

    1 <= nums.length <= 105
    0 <= nums[i] <= 105

Accepted
458K
Submissions
774.5K
Acceptance Rate
59.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (82)
Related Topics
Array
Binary Search

*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid;
        while(left < right){
            mid = (left + right)/2;
            if((mid & 1 && nums[mid] == nums[mid-1]) || (!(mid & 1) && nums[mid] == nums[mid+1]))
                left = mid+1;
            else    right = mid; 
        } 
        return nums[left];
    }
};