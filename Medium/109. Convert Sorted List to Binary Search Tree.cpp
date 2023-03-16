/*
109. Convert Sorted List to Binary Search Tree
Medium
6.7K
142
company
Amazon
company
Facebook
company
Microsoft

Given the head of a singly linked list where elements are sorted in ascending order, convert it to a
height-balanced
binary search tree.

 

Example 1:

Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.

Example 2:

Input: head = []
Output: []

 

Constraints:

    The number of nodes in head is in the range [0, 2 * 104].
    -105 <= Node.val <= 105

Accepted
468.9K
Submissions
780K
Acceptance Rate
60.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (37)
Similar Questions
Convert Sorted Array to Binary Search Tree
Easy
Create Binary Tree From Descriptions
Medium
Related Topics
Linked List
Divide and Conquer
Tree
Binary Search Tree
Binary Tree

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    vector<int> nums;

    void build_nums(ListNode* head)
    {
        while(head)
        {
            nums.push_back(head->val);
            head = head->next;
        }
    }

    TreeNode* helper(int left, int right, vector<int>& nums) 
    {
        if(left > right)    return nullptr;

        int mid = (left + right) / 2;
        
        TreeNode *root = new TreeNode(nums[mid]);

        root->left = helper(left, mid-1, nums);
        root->right = helper(mid+1, right, nums);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) 
    {
        build_nums(head);
        
        return helper(0, nums.size()-1, nums);
    }
};