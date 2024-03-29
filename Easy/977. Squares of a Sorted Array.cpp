/*
977. Squares of a Sorted Array
Easy
7.9K
198
company
Yandex
company
Amazon
company
Yahoo

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

 

Constraints:

    1 <= nums.length <= 104
    -104 <= nums[i] <= 104
    nums is sorted in non-decreasing order.

 
Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?
Accepted
1.4M
Submissions
2M
Acceptance Rate
71.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (37)
Similar Questions
Merge Sorted Array
Easy
Sort Transformed Array
Medium
Related Topics
Array
Two Pointers
Sorting
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int length = nums.size();
        
        vector<int> ans(length);

        int left = 0;
        int right = length - 1;
        int index = length - 1;

        while(left <= right)
        {
            if(abs(nums[left]) > abs(nums[right]))
            {
                ans[index--] = abs(nums[left])*abs(nums[left]);
                left++;
            }
            else
            {
                ans[index--] = abs(nums[right])*abs(nums[right]);
                right--;
            }
        }
        return ans;
    }
};