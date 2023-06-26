/*
1569. Number of Ways to Reorder Array to Get Same BST
Hard
1.6K
188
company
Amazon
company
Google

Given an array nums that represents a permutation of integers from 1 to n. We are going to construct a binary search tree (BST) by inserting the elements of nums in order into an initially empty BST. Find the number of different ways to reorder nums so that the constructed BST is identical to that formed from the original array nums.

    For example, given nums = [2,1,3], we will have 2 as the root, 1 as a left child, and 3 as a right child. The array [2,3,1] also yields the same BST but [3,2,1] yields a different BST.

Return the number of ways to reorder nums such that the BST formed is identical to the original BST formed from nums.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [2,1,3]
Output: 1
Explanation: We can reorder nums to be [2,3,1] which will yield the same BST. There are no other ways to reorder nums which will yield the same BST.

Example 2:

Input: nums = [3,4,5,1,2]
Output: 5
Explanation: The following 5 arrays will yield the same BST: 
[3,1,2,4,5]
[3,1,4,2,5]
[3,1,4,5,2]
[3,4,1,2,5]
[3,4,1,5,2]

Example 3:

Input: nums = [1,2,3]
Output: 0
Explanation: There are no other orderings of nums that will yield the same BST.

 

Constraints:

    1 <= nums.length <= 1000
    1 <= nums[i] <= nums.length
    All integers in nums are distinct.

Accepted
49.3K
Submissions
91.6K
Acceptance Rate
53.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (93)
Related Topics
Array
Math
Divide and Conquer
Dynamic Programming
Tree
Union Find
Binary Search Tree
Memoization
Combinatorics
Binary Tree
*/
class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int nums_len = nums.size();

        pascal.resize(nums_len + 1);

        for(int i = 0; i <= nums_len; i++)
        {
            pascal[i] = vector<long long> (i + 1, 1);

            for(int j = 1; j < i; j++)
                pascal[i][j] = (pascal[i - 1][j] + pascal[i - 1][j - 1]) % mod;
        }

        return (dfs(nums) - 1) % mod;
    }

private:
    vector<vector<long long>> pascal;
    int mod = 1e9 + 7;

    long long dfs(vector<int> &nums) 
    {
        if(nums.size() <= 2)
            return 1;

        vector<int> left_subtree;
        vector<int> right_subtree;

        for(int i = 1; i < nums.size(); i++)
            if(nums[i] < nums[0])
                left_subtree.push_back(nums[i]);
            else 
                right_subtree.push_back(nums[i]);

        long long left_way = dfs(left_subtree) % mod;
        long long right_way = dfs(right_subtree) % mod;

        return (((left_way * right_way) % mod) * pascal[nums.size() - 1][left_subtree.size()]) % mod;
    }
};