/*
2195. Append K Integers With Minimal Sum
Medium
617
286
company
Amazon

You are given an integer array nums and an integer k. Append k unique positive integers that do not appear in nums to nums such that the resulting total sum is minimum.

Return the sum of the k integers appended to nums.

 

Example 1:

Input: nums = [1,4,25,10,25], k = 2
Output: 5
Explanation: The two unique positive integers that do not appear in nums which we append are 2 and 3.
The resulting sum of nums is 1 + 4 + 25 + 10 + 25 + 2 + 3 = 70, which is the minimum.
The sum of the two integers appended is 2 + 3 = 5, so we return 5.

Example 2:

Input: nums = [5,6], k = 6
Output: 25
Explanation: The six unique positive integers that do not appear in nums which we append are 1, 2, 3, 4, 7, and 8.
The resulting sum of nums is 5 + 6 + 1 + 2 + 3 + 4 + 7 + 8 = 36, which is the minimum. 
The sum of the six integers appended is 1 + 2 + 3 + 4 + 7 + 8 = 25, so we return 25.

 

Constraints:

    1 <= nums.length <= 105
    1 <= nums[i] <= 109
    1 <= k <= 108

Accepted
26.7K
Submissions
107K
Acceptance Rate
25.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (6)
Similar Questions
Remove K Digits
Medium
Find All Numbers Disappeared in an Array
Easy
Kth Missing Positive Number
Easy
Maximum Number of Integers to Choose From a Range I
Medium
Maximum Number of Integers to Choose From a Range II
Medium
Related Topics
Array
Math
Greedy
Sorting
*/
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        set<int> unique(nums.begin(), nums.end());

        long long minimal_k_sum = (long(k) * (long(k + 1))) / 2;

        for(auto uk : unique)
            if(uk <= k)
            {
                minimal_k_sum -= uk;
                minimal_k_sum += k + 1;
                k++;
            }
            else 
                break;
        
        return minimal_k_sum;
    }
};