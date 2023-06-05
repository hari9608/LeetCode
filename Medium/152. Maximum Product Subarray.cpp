/*
152. Maximum Product Subarray
Medium
15.6K
472
company
Amazon
company
Microsoft
company
Adobe

Given an integer array nums, find a
subarray
that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

 

Constraints:

    1 <= nums.length <= 2 * 104
    -10 <= nums[i] <= 10
    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

Accepted
981.9K
Submissions
2.8M
Acceptance Rate
34.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (42)
Similar Questions
Maximum Subarray
Medium
House Robber
Medium
Product of Array Except Self
Medium
Maximum Product of Three Numbers
Easy
Subarray Product Less Than K
Medium
Related Topics
Array
Dynamic Programming
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (!nums.size()) 
            return 0;

        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = max_so_far;

        for (int i = 1; i < nums.size(); i++) 
        {
            int curr = nums[i];
            int temp_max = max(curr, max(max_so_far * curr, min_so_far * curr));

            min_so_far = min(curr, min(max_so_far * curr, min_so_far * curr));

            max_so_far = temp_max;

            result = max(max_so_far, result);
        }

        return result;
    }
};