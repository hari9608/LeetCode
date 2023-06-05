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

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row_size = len(matrix)
        col_size = len(matrix[0])
        left = 0
        right = row_size * col_size - 1

        while left <= right:
            temp_tar_ind = left + (right - left) // 2
            temp_target = matrix[temp_tar_ind // col_size][temp_tar_ind % col_size]
            if target == temp_target:
                return True
            elif target < temp_target:
                right = temp_tar_ind - 1
            else:
                left = temp_tar_ind + 1

        return False