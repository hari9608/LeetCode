/*

238. Product of Array Except Self
Medium
16.7K
921
company
Amazon
company
Google
company
Microsoft

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

 

Constraints:

    2 <= nums.length <= 105
    -30 <= nums[i] <= 30
    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

 

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
Accepted
1.6M
Submissions
2.4M
Acceptance Rate
65.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (46)
Similar Questions
Trapping Rain Water
Hard
Maximum Product Subarray
Medium
Paint House II
Hard
Minimum Difference in Sums After Removal of Elements
Hard
Related Topics
Array
Prefix Sum

*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pro = 1;

        int sufPro[nums.size()];
        for(int i=nums.size() - 1; i>=0; i--)  {
            sufPro[i] = pro;
            pro *= nums[i];
        }
        vector<int> res;
        pro = 1;
        for(int i=0; i<nums.size(); i++) {
            res.push_back(pro * sufPro[i]);
            pro *= nums[i];
        }
        return res;
    }
};