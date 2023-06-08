/*
905. Sort Array By Parity
Easy
4.4K
136
company
Amazon
company
Facebook
company
Microsoft

Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.

 

Example 1:

Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

Example 2:

Input: nums = [0]
Output: [0]

 

Constraints:

    1 <= nums.length <= 5000
    0 <= nums[i] <= 5000

Accepted
605.8K
Submissions
802K
Acceptance Rate
75.5%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (21)
Similar Questions
Sort Even and Odd Indices Independently
Easy
Largest Number After Digit Swaps by Parity
Easy
Related Topics
Array
Two Pointers
Sorting
*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;       // point to first odd num in the array
        int right = 0;      // point to first even num in the array
        int len = nums.size();

        while(right < len && !(nums[left] & 1))    
            left++, right++;

        while(right < len)
        {
            while(right < len && nums[right] & 1)      
                right++;
            if(right < len)     swap(nums[left++], nums[right++]);
        }

        return nums;
    }
};