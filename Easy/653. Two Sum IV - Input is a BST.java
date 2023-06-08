/*
653. Two Sum IV - Input is a BST
Easy
5.9K
241
company
Amazon
company
Google
company
Bloomberg

Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

 

Example 1:

Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Example 2:

Input: root = [5,3,6,2,4,null,7], k = 28
Output: false

 

Constraints:

    The number of nodes in the tree is in the range [1, 104].
    -104 <= Node.val <= 104
    root is guaranteed to be a valid binary search tree.
    -105 <= k <= 105

Accepted
460.8K
Submissions
754.8K
Acceptance Rate
61.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (17)
Similar Questions
Two Sum
Easy
Two Sum II - Input Array Is Sorted
Medium
Two Sum III - Data structure design
Easy
Two Sum BSTs
Medium
Related Topics
Hash Table
Two Pointers
Tree
Depth-First Search
Breadth-First Search
Binary Search Tree
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
    public boolean find(TreeNode root, int k, Set < Integer > set) 
    {
        if (root == null)
            return false;

        if (set.contains(k - root.val))
            return true;

        set.add(root.val);

        return find(root.left, k, set) || find(root.right, k, set);
    }
    public boolean findTarget(TreeNode root, int k) {
        Set < Integer > set = new HashSet();

        return find(root, k, set);
    }
}