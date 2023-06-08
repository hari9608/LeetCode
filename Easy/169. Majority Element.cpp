/*
169. Majority Element
Easy
15.1K
452
company
Amazon
company
Apple
company
Google

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3

Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

 

Constraints:

    n == nums.length
    1 <= n <= 5 * 104
    -109 <= nums[i] <= 109

 
Follow-up: Could you solve the problem in linear time and in O(1) space?
Accepted
1.8M
Submissions
2.8M
Acceptance Rate
63.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (80)
Similar Questions
Majority Element II
Medium
Check If a Number Is Majority Element in a Sorted Array
Easy
Most Frequent Even Element
Easy
Related Topics
Array
Hash Table
Divide and Conquer
Sorting
Counting
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = nums[0];
        int count = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == vote) ++count;
            else --count;
            if(!count){
                vote = nums[i];
                count = 1;
            }
        }
        return vote;
    }
};