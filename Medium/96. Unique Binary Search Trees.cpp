/*
96. Unique Binary Search Trees
Medium
8.9K
353
company
Apple
company
Amazon
company
Microsoft

Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 

Example 1:

Input: n = 3
Output: 5

Example 2:

Input: n = 1
Output: 1

 

Constraints:

    1 <= n <= 19

Accepted
559.7K
Submissions
938.7K
Acceptance Rate
59.6%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (19)
Similar Questions
Unique Binary Search Trees II
Medium
Related Topics
Math
Dynamic Programming
Tree
Binary Search Tree
Binary Tree
*/
class Solution {
public:
    int numTrees(int n) {
        long num_trees = 1;
        for (int i = 0; i < n; i++) 
            num_trees = num_trees * 2 * (2 * i + 1) / (i + 2);

        return num_trees;
    }
};