/*
1295. Find Numbers with Even Number of Digits
Easy
2K
113
company
Amazon
company
Quora

Given an array nums of integers, return how many of them contain an even number of digits.

 

Example 1:

Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.

Example 2:

Input: nums = [555,901,482,1771]
Output: 1 
Explanation: 
Only 1771 contains an even number of digits.

 

Constraints:

    1 <= nums.length <= 500
    1 <= nums[i] <= 105

Accepted
561.3K
Submissions
728.9K
Acceptance Rate
77.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (22)
Similar Questions
Finding 3-Digit Even Numbers
Easy
Number of Even and Odd Bits
Easy
Related Topics
Array
*/
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for(auto val : nums)
            if(val>9 && val<100 || val>999 && val<10000 || val>99999)
                result++;
        return result;
    }
};