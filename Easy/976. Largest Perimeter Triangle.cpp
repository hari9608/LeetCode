/*
976. Largest Perimeter Triangle
Easy
2.8K
392
company
Apple
company
Tesla
company
Adobe

Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.

 

Example 1:

Input: nums = [2,1,2]
Output: 5
Explanation: You can form a triangle with three side lengths: 1, 2, and 2.

Example 2:

Input: nums = [1,2,1,10]
Output: 0
Explanation: 
You cannot use the side lengths 1, 1, and 2 to form a triangle.
You cannot use the side lengths 1, 1, and 10 to form a triangle.
You cannot use the side lengths 1, 2, and 10 to form a triangle.
As we cannot use any three side lengths to form a triangle of non-zero area, we return 0.

 

Constraints:

    3 <= nums.length <= 104
    1 <= nums[i] <= 106

Accepted
208.8K
Submissions
381.4K
Acceptance Rate
54.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (18)
Similar Questions
Largest Triangle Area
Easy
Related Topics
Array
Math
Greedy
Sorting
*/
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int ind = nums.size() - 3; ind >= 0; ind--)    if(nums[ind] + nums[ind + 1] > nums[ind + 2])    return nums[ind] + nums[ind + 1] + nums[ind + 2];

        return 0;
    }
};