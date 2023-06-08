/*
303. Range Sum Query - Immutable
Easy
2.8K
1.8K
company
Facebook
company
Adobe
company
Bloomberg

Given an integer array nums, handle multiple queries of the following type:

    Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.

Implement the NumArray class:

    NumArray(int[] nums) Initializes the object with the integer array nums.
    int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

 

Example 1:

Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]

Explanation
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3

 

Constraints:

    1 <= nums.length <= 104
    -105 <= nums[i] <= 105
    0 <= left <= right < nums.length
    At most 104 calls will be made to sumRange.

Accepted
442.5K
Submissions
736.4K
Acceptance Rate
60.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (8)
Similar Questions
Range Sum Query 2D - Immutable
Medium
Range Sum Query - Mutable
Medium
Maximum Size Subarray Sum Equals k
Medium
Related Topics
Array
Design
Prefix Sum
*/
class NumArray {
public:
    vector<int> num_array;
    NumArray(vector<int>& nums) {
        num_array.push_back(0);
        for(int i = 0; i < nums.size(); i++)
            num_array.push_back(num_array[i] + nums[i]);
    }
    
    int sumRange(int left, int right) {
        
        return num_array[right + 1] - num_array[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */