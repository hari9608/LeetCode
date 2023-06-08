/*
1929. Concatenation of Array
Easy
2.4K
294
company
Apple
company
Uber
company
Google

Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).

Specifically, ans is the concatenation of two nums arrays.

Return the array ans.

 

Example 1:

Input: nums = [1,2,1]
Output: [1,2,1,1,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
- ans = [1,2,1,1,2,1]

Example 2:

Input: nums = [1,3,2,1]
Output: [1,3,2,1,1,3,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
- ans = [1,3,2,1,1,3,2,1]

 

Constraints:

    n == nums.length
    1 <= n <= 1000
    1 <= nums[i] <= 1000

Accepted
441.1K
Submissions
490.8K
Acceptance Rate
89.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (37)
Related Topics
Array
*/
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int j=0;
        int k=nums.size();
        vector<int> ans(2*k);
        for(int i=0; i<nums.size(); i++){
            ans[i] = nums[i];
            ans[k++] = nums[i];
        }
        return ans;
    }
};