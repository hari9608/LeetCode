/*
75. Sort Colors
Medium
14.3K
512
company
Amazon
company
Yahoo
company
Microsoft

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]

 

Constraints:

    n == nums.length
    1 <= n <= 300
    nums[i] is either 0, 1, or 2.

 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?
Accepted
1.4M
Submissions
2.3M
Acceptance Rate
58.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (53)
Similar Questions
Sort List
Medium
Wiggle Sort
Medium
Wiggle Sort II
Medium
Related Topics

	Array
Two Pointers
Sorting
*/
class Solution {
public:
    void swap(int *a, int *b){
        int t = *a;
        *a = *b;
        *b = t;
    }
    void sortColors(vector<int>& nums) {
        int zi = 0;
        int mi = 0;
        int ti = nums.size() - 1;
        while(mi <= ti){
            if(nums[mi] == 0) swap(&nums[zi++], &nums[mi++]);
            else if(nums[mi] == 1) mi++;
            else swap(&nums[mi], &nums[ti--]);
        }
    }
};