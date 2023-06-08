/*
1403. Minimum Subsequence in Non-Increasing Order
Easy
501
463
Mercari

Given the array nums, obtain a subsequence of the array whose sum of elements is strictly greater than the sum of the non included elements in such subsequence. 

If there are multiple solutions, return the subsequence with minimum size and if there still exist multiple solutions, return the subsequence with the maximum total sum of all its elements. A subsequence of an array can be obtained by erasing some (possibly zero) elements from the array. 

Note that the solution with the given constraints is guaranteed to be unique. Also return the answer sorted in non-increasing order.

 

Example 1:

Input: nums = [4,3,10,9,8]
Output: [10,9] 
Explanation: The subsequences [10,9] and [10,8] are minimal such that the sum of their elements is strictly greater than the sum of elements not included. However, the subsequence [10,9] has the maximum total sum of its elements. 

Example 2:

Input: nums = [4,4,7,6,7]
Output: [7,7,6] 
Explanation: The subsequence [7,7] has the sum of its elements equal to 14 which is not strictly greater than the sum of elements not included (14 = 4 + 4 + 6). Therefore, the subsequence [7,6,7] is the minimal satisfying the conditions. Note the subsequence has to be returned in non-decreasing order.  

 

Constraints:

    1 <= nums.length <= 500
    1 <= nums[i] <= 100

Accepted
62.5K
Submissions
86.5K
Acceptance Rate
72.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (6)
Similar Questions
Count Hills and Valleys in an Array
Easy
Related Topics
Array
Greedy
Sorting
*/
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        priority_queue<int> max_first;
        vector<int> subsequence;
        int sum = 0;
        int sum1 = 0;

        for(auto num : nums)
        {
            max_first.push(num);
            sum += num;
        }

        while(max_first.size() > 0)
        {
            sum1 += max_first.top();
            subsequence.push_back(max_first.top());
            max_first.pop();
            if(sum-sum1 < (sum+1)/2)    break;    // check it reaches the half of sum reaches sum1(subsequence sum)
        }

        return subsequence;
    }
};