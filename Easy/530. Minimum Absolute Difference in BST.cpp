/*
530. Minimum Absolute Difference in BST
Easy
3.8K
184
company
Amazon
company
Google
company
Facebook

Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

 

Example 1:

Input: root = [4,2,6,1,3]
Output: 1

Example 2:

Input: root = [1,0,48,null,null,12,49]
Output: 1

 

Constraints:

    The number of nodes in the tree is in the range [2, 104].
    0 <= Node.val <= 105

 

Note: This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
Accepted
280.2K
Submissions
474.8K
Acceptance Rate
59.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (37)
💡 Discussion Rules

1. Please don't post any solutions in this discussion.

2. The problem discussion is for asking questions about the problem or for sharing tips - anything except for solutions.

3. If you'd like to share your solution for feedback and ideas, please head to the solutions tab and post it there.
aeroabrar_31
100 Days Badge 2022
Feb 17, 2023

How many of you came here today after solving 'Minimum Distance between Nodes' and submitted the same solution just to increase your questions count ?
25
4
bigwetmaster
Nov 03, 2020

We are supposed to find the minimum absolute difference between any two nodes. If the absolute difference is desired, why for certain test cases the expected results are negative numbers? Also, if I understand correctly, the difference can be taken between any two nodes. However, all the solutions I have seen are comparing inorder nieghbors. I am confused...
18
4
swati_dubey
Jun 14, 2023

I think temperature of June in Gurgaon is inversely proportional to difficulty level of leetcode challenge.
14
6
coder_ges
May 01, 2019

What is the difference between question "Minimun Absolute difference in BST" and "Minimum distance between two nodes in BST"?
10
1
sasukesharma
Data Structure I
Jun 14, 2023

Isn't this week going smooth, maybe back to back HARDs are coming.
5
1
ayushap05
50 Days Badge 2022
Feb 18, 2023

If this question is same as Minimum Distance Between BST Nodes then why keep both of them?
5
daring-calf
100 Days Badge 2022
Jun 14, 2023

Yes, easy, my ass.
4
anwendeng
Mar LeetCoding Challenge
Jun 14, 2023

Use inorder traversal to solve binary tree problem.
4
AlecLC
Mar LeetCoding Challenge
Feb 17, 2023
Hint

Find the difference between the minimum node on the right and the maximum node on the left

This is the same as finding the minimum difference between adjacent elements in a sorted array of node values
3
layyy
Jun 14, 2023

Inorder traversal
Tip
2
Similar Questions
K-diff Pairs in an Array
Medium
Related Topics
Tree
Depth-First Search
Breadth-First Search
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
    int minimum_difference = INT_MAX;
    TreeNode *prev;
    
    void inorderTraversal(TreeNode *root)
    {
        if(root)
        {
            inorderTraversal(root->left);

            if(prev && abs(prev->val - root->val) < minimum_difference)
                minimum_difference = abs(root->val - prev->val);
            
            prev = root;
            inorderTraversal(root->right);
        }
    }

    int getMinimumDifference(TreeNode* root) {
        inorderTraversal(root);
        return minimum_difference;
    }
};