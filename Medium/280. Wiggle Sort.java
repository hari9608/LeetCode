/*
280. Wiggle Sort
Medium
1.1K
97
company
Microsoft
company
Amazon
company
Google

Given an integer array nums, reorder it such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

You may assume the input array always has a valid answer.

 

Example 1:

Input: nums = [3,5,2,1,6,4]
Output: [3,5,1,6,2,4]
Explanation: [1,6,2,5,3,4] is also accepted.

Example 2:

Input: nums = [6,6,5,6,3,8]
Output: [6,6,5,6,3,8]

 

Constraints:

    1 <= nums.length <= 5 * 104
    0 <= nums[i] <= 104
    It is guaranteed that there will be an answer for the given input nums.

 

Follow up: Could you solve the problem in O(n) time complexity?
Accepted
131K
Submissions
195.1K
Acceptance Rate
67.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (10)
Similar Questions
Sort Colors
Medium
Wiggle Sort II
Medium
Array With Elements Not Equal to Average of Neighbors
Medium
Related Topics
Array
Greedy
Sorting
*/
class Solution {
    public void wiggleSort(int[] nums) {

        for(int i = 0; i < nums.length - 1; i++)
        {
            if(((i & 1) == 0 && nums[i] > nums[i + 1]) || ((i & 1) == 1 && nums[i] < nums[i + 1]))
            {
                int temp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = temp;
            }
        }
        
    }
}