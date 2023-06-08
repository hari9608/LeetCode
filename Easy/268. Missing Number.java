/*
268. Missing Number
Easy
9.5K
3.1K
company
Amazon
company
Microsoft
company
Google

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.

 

Constraints:

    n == nums.length
    1 <= n <= 104
    0 <= nums[i] <= n
    All the numbers of nums are unique.

 

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?
Accepted
1.5M
Submissions
2.4M
Acceptance Rate
62.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (79)
Similar Questions
First Missing Positive
Hard
Single Number
Easy
Find the Duplicate Number
Medium
Couples Holding Hands
Hard
Find Unique Binary String
Medium
Related Topics
Array
Hash Table
Math
Binary Search
Bit Manipulation
Sorting
*/
class Solution {
    public int missingNumber(int[] nums) {
        int len = nums.length;
        int sum1 = (len*(len+1))/2;
        int sum2 = Arrays.stream(nums).sum();
        
        return sum1 - sum2;
    }
}