/*
1493. Longest Subarray of 1's After Deleting One Element
Medium
3.1K
51
company
Yandex

Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.

 

Constraints:

    1 <= nums.length <= 105
    nums[i] is either 0 or 1.

Accepted
141.8K
Submissions
214.4K
Acceptance Rate
66.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (36)
Related Topics
Array
Dynamic Programming
Sliding Window
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero_count = 0;
        int longest_subarray = 0;
        int start = 0;

        for(int ind = 0; ind < nums.size(); ind++)
        {
            zero_count += (!nums[ind]);

            while(zero_count > 1)
            {
                zero_count -= (!nums[start]);
                start++;
            }

            longest_subarray = max(longest_subarray, ind - start);
        }

        return longest_subarray;
    }
};