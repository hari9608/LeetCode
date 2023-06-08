/*
108. Convert Sorted Array to Binary Search Tree
Easy
9.6K
481
company
Amazon
company
Microsoft
company
Adobe

Given an integer array nums where the elements are sorted in ascending order, convert it to a
height-balanced
binary search tree.

 

Example 1:

Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:

Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

 

Constraints:

    1 <= nums.length <= 104
    -104 <= nums[i] <= 104
    nums is sorted in a strictly increasing order.

Accepted
1M
Submissions
1.4M
Acceptance Rate
70.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (30)
Similar Questions
Convert Sorted List to Binary Search Tree
Medium
Related Topics
Array
Divide and Conquer
Tree
Binary Search Tree
Binary Tree
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(int left, int right, vector<int>& nums) 
    {
        if(left > right)    return nullptr;

        int mid = (left + right) / 2;
        
        TreeNode *root = new TreeNode(nums[mid]);

        root->left = helper(left, mid-1, nums);
        root->right = helper(mid+1, right, nums);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(0, nums.size()-1, nums);
    }
};