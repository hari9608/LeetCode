/*
74. Search a 2D Matrix
Medium
11.9K
343
company
Amazon
company
Adobe
company
Apple

You are given an m x n integer matrix matrix with the following two properties:

    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

 

Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 100
    -104 <= matrix[i][j], target <= 104

Accepted
1.2M
Submissions
2.5M
Acceptance Rate
47.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (54)
Similar Questions
Search a 2D Matrix II
Medium
Split Message Based on Limit
Hard
Related Topics
Array
Binary Search
Matrix
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_size = matrix.size();
        int col_size = matrix[0].size();

        for(int r=0; r<row_size; r++)
        {
            if(target > matrix[r][col_size - 1])    continue;

            for(int c=0; c<col_size; c++)
                if(target == matrix[r][c])  
                    return true;

            return false;
        }

        return false;
    }
};