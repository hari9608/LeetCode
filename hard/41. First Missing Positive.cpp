/*
41. First Missing Positive
Hard
13.7K
1.6K
company
Amazon
company
Microsoft
company
IBM

Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.

Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.

Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.

 

Constraints:

    1 <= nums.length <= 105
    -231 <= nums[i] <= 231 - 1


Similar Questions
Missing Number
Easy
Find the Duplicate Number
Medium
Find All Numbers Disappeared in an Array
Easy
Couples Holding Hands
Hard
Smallest Number in Infinite Set
Medium
Maximum Number of Integers to Choose From a Range I
Medium
Smallest Missing Non-negative Integer After Operations
Medium
Maximum Number of Integers to Choose From a Range II
Medium

Related Topics
Array
Hash Table
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int nums_len = nums.size();
        bool ones = false;

        for(auto num : nums)
            if(num == 1)
            {    
                ones = true;
                break;
            }

        if(!ones)   return 1;

        for(int ind=0; ind<nums_len; ind++)
            if(nums[ind] <= 0 || nums[ind] > nums_len)
                nums[ind] = 1;

        for(int ind=0; ind<nums_len; ind++)
        {
            int a = abs(nums[ind]);
            if(a == nums_len)   
                nums[0] = -abs(nums[0]);
            else                
                nums[a] = -abs(nums[a]);
        }

        for(int ind=1; ind<nums_len; ind++)
            if(nums[ind] > 0)
                return ind;
        
        return nums[0] > 0 ? nums_len : nums_len + 1;
    }
};