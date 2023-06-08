/*
1608. Special Array With X Elements Greater Than or Equal X
Easy
1.4K
235
company
Google

You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.

Notice that x does not have to be an element in nums.

Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.

 

Example 1:

Input: nums = [3,5]
Output: 2
Explanation: There are 2 values (3 and 5) that are greater than or equal to 2.

Example 2:

Input: nums = [0,0]
Output: -1
Explanation: No numbers fit the criteria for x.
If x = 0, there should be 0 numbers >= x, but there are 2.
If x = 1, there should be 1 number >= x, but there are 0.
If x = 2, there should be 2 numbers >= x, but there are 0.
x cannot be greater since there are only 2 numbers in nums.

Example 3:

Input: nums = [0,4,3,0,4]
Output: 3
Explanation: There are 3 values that are greater than or equal to 3.

 

Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 1000

Accepted
67.9K
Submissions
112.4K
Acceptance Rate
60.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (9)
Related Topics
Array
Binary Search
Sorting
*/
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int left = 0;
        int right = nums[0];

        for(int i=0; i<nums.size(); i++)    right = nums[i] > right ? nums[i] : right;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            int find = 0;

            for(int i = 0; i<nums.size(); i++)
                if(nums[i] >= mid)
                    find++;
            
            if(find == mid)         return mid;
            else if(find > mid)     left = mid + 1;
            else                    right = mid - 1;
        }

        return -1;
    }
};