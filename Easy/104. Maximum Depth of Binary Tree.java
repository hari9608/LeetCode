/*
104. Maximum Depth of Binary Tree
Easy
10.9K
174
company
Yandex
company
Amazon
company
Apple

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 3

Example 2:

Input: root = [1,null,2]
Output: 2

 

Constraints:

    The number of nodes in the tree is in the range [0, 104].
    -100 <= Node.val <= 100

Accepted
2.4M
Submissions
3.2M
Acceptance Rate
74.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (93)
Similar Questions
Balanced Binary Tree
Easy
Minimum Depth of Binary Tree
Easy
Maximum Depth of N-ary Tree
Easy
Time Needed to Inform All Employees
Medium
Amount of Time for Binary Tree to Be Infected
Medium
Height of Binary Tree After Subtree Removal Queries
Hard
Related Topics
Tree
Depth-First Search
Breadth-First Search
Binary Tree
*/
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    public int maxDepth(TreeNode root) {
        if(root == null)   
            return 0;

        return Math.max(1 + maxDepth(root.left), 1 + maxDepth(root.right));
    }
}