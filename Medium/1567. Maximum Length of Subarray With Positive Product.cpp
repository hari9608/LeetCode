/*
1567. Maximum Length of Subarray With Positive Product
Medium
2.2K
59
company
Arcesium
company
Amazon
company
Adobe

Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.

A subarray of an array is a consecutive sequence of zero or more values taken out of that array.

Return the maximum length of a subarray with positive product.

 

Example 1:

Input: nums = [1,-2,-3,4]
Output: 4
Explanation: The array nums already has a positive product of 24.

Example 2:

Input: nums = [0,1,-2,-3,-4]
Output: 3
Explanation: The longest subarray with positive product is [1,-2,-3] which has a product of 6.
Notice that we cannot include 0 in the subarray since that'll make the product 0 which is not positive.

Example 3:

Input: nums = [-1,-2,-3,0,1]
Output: 2
Explanation: The longest subarray with positive product is [-1,-2] or [-2,-3].

 

Constraints:

    1 <= nums.length <= 105
    -109 <= nums[i] <= 109

Accepted
84.5K
Submissions
191.7K
Acceptance Rate
44.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (4)
Related Topics
Array
Dynamic Programming
Greedy
*/
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos(n);
        vector<int> neg(n);
        
        if (nums[0] > 0) pos[0] = 1;
        if (nums[0] < 0) neg[0] = 1;

        int ans = pos[0];
        
        for (int i = 1; i < n; i++) 
        {
            if (nums[i] > 0) 
            {
                pos[i] = 1 + pos[i - 1];
                neg[i] = neg[i - 1] > 0 ? 1 + neg[i - 1] : 0;
            } 
            else if (nums[i] < 0) 
            {
                pos[i] = neg[i - 1] > 0 ? 1 + neg[i - 1] : 0;
                neg[i] = 1 + pos[i - 1];
            }
            ans = max(ans, pos[i]);
        }

        return ans;
    }
};