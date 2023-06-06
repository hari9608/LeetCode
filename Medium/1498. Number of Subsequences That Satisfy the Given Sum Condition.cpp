/*
1498. Number of Subsequences That Satisfy the Given Sum Condition
Medium
3.4K
300
company
Bloomberg
company
Amazon
company
Adobe

You are given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)

Example 2:

Input: nums = [3,3,6,8], target = 10
Output: 6
Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
[3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]

Example 3:

Input: nums = [2,3,3,4,6,7], target = 12
Output: 61
Explanation: There are 63 non-empty subsequences, two of them do not satisfy the condition ([6,7], [7]).
Number of valid subsequences (63 - 2 = 61).

 

Constraints:

    1 <= nums.length <= 105
    1 <= nums[i] <= 106
    1 <= target <= 106

Accepted
96.7K
Submissions
216K
Acceptance Rate
44.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (61)
Related Topics
Array
Two Pointers
Binary Search
Sorting
*/
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int nums_len = nums.size();
        int mod = 1000000007;
        int num_subseq = 0;
        
        sort(nums.begin(), nums.end());

        vector<int> pows(nums_len);
        pows[0] = 1;

        for(int i = 1; i < nums_len; i++)
            pows[i] = (pows[i - 1] * 2) % mod;

        int left = 0;
        int right = nums_len - 1;

        while(left <= right)
            if(nums[left] + nums[right] > target)
                right--;
            else
            {
                num_subseq = (num_subseq + pows[right - left]) % mod;
                left++;
            }
 
        return num_subseq;
    }
};