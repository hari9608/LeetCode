/*
1913. Maximum Product Difference Between Two Pairs
Easy
746
37

The product difference between two pairs (a, b) and (c, d) is defined as (a * b) - (c * d).

    For example, the product difference between (5, 6) and (2, 7) is (5 * 6) - (2 * 7) = 16.

Given an integer array nums, choose four distinct indices w, x, y, and z such that the product difference between pairs (nums[w], nums[x]) and (nums[y], nums[z]) is maximized.

Return the maximum such product difference.

 

Example 1:

Input: nums = [5,6,2,7,4]
Output: 34
Explanation: We can choose indices 1 and 3 for the first pair (6, 7) and indices 2 and 4 for the second pair (2, 4).
The product difference is (6 * 7) - (2 * 4) = 34.

Example 2:

Input: nums = [4,2,5,9,7,4,8]
Output: 64
Explanation: We can choose indices 3 and 6 for the first pair (9, 8) and indices 1 and 5 for the second pair (2, 4).
The product difference is (9 * 8) - (2 * 4) = 64.

 

Constraints:

    4 <= nums.length <= 104
    1 <= nums[i] <= 104

Accepted
87.7K
Submissions
108.2K
Acceptance Rate
81.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (5)
Related Topics
Array
Sorting
*/
class Solution {
public:
    int minElement(vector<int>& nums, int len, int index)
    {
        int min_ind = 0;
        int min = INT_MAX;
        for(int i=0; i<len; i++)    
            if(nums[i] < min && i != index)
            {
                min = nums[i];
                min_ind = i;
            }
            
        return min_ind;
    }

    int maxElement(vector<int>& nums, int len, int index)
    {
        int max_ind = 0;
        int max = INT_MIN;
        for(int i=0; i<len; i++)    
            if(nums[i] > max && i != index)
            {
                max = nums[i];
                max_ind = i;
            }

        return max_ind;
    }

    int maxProductDifference(vector<int>& nums) {
        int len = nums.size();
        int min_01 = minElement(nums, len, -1);
        int min_02 = minElement(nums, len, min_01);
        int max_01 = maxElement(nums, len, -1);
        int max_02 = maxElement(nums, len, max_01);
        
        return (nums[max_02] * nums[max_01]) - (nums[min_01] * nums[min_02]);
    }
};