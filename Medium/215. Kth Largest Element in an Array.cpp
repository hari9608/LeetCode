/*
215. Kth Largest Element in an Array
Medium
13.4K
663
company
Facebook
company
Amazon
company
Spotify

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

You must solve it in O(n) time complexity.

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

 

Constraints:

    1 <= k <= nums.length <= 105
    -104 <= nums[i] <= 104

Accepted
1.7M
Submissions
2.6M
Acceptance Rate
66.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (43)
Similar Questions
Wiggle Sort II
Medium
Top K Frequent Elements
Medium
Third Maximum Number
Easy
Kth Largest Element in a Stream
Easy
K Closest Points to Origin
Medium
Find the Kth Largest Integer in the Array
Medium
Find Subsequence of Length K With the Largest Sum
Easy
K Highest Ranked Items Within a Price Range
Medium
Related Topics
Array
Divide and Conquer
Sorting
Heap (Priority Queue)
Quickselect

*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        while(k>1 && k--) q.pop();
        return q.top(); 

//        nth_element(nums.begin(), nums.begin()+k, nums.end(), greater<int>());
//        return nums[k-1];
    }
};