/*
1464. Maximum Product of Two Elements in an Array
Easy
1.6K
188
company
Amazon
company
Samsung
Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).

 

Example 1:

Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 

Example 2:

Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.

Example 3:

Input: nums = [3,7]
Output: 12

 

Constraints:

    2 <= nums.length <= 500
    1 <= nums[i] <= 10^3

Accepted
193.7K
Submissions
241.7K
Acceptance Rate
80.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (7)
Related Topics
Array
Sorting
Heap (Priority Queue)
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        
        sort(nums.begin(), nums.end());

        return (nums[len-1]-1) * (nums[len-2]-1);
    }
};