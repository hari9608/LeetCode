/*
1351. Count Negative Numbers in a Sorted Matrix
Easy
3.9K
106
company
Amazon
company
Uber
company
Microsoft

Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

 

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 100
    -100 <= grid[i][j] <= 100

 
Follow up: Could you find an O(n + m) solution?
Accepted
288.8K
Submissions
376.6K
Acceptance Rate
76.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (30)
Similar Questions
Maximum Count of Positive Integer and Negative Integer
Easy
Related Topics
Array
Binary Search
Matrix
*/
class Solution {
    public int countNegatives(int[][] grid) {
        int negative_count = 0;
        int col_size = grid[0].length;
        int curr_col = col_size - 1;

        for(int[] row : grid)
        {
            while(curr_col >= 0 && row[curr_col] < 0)
                curr_col--;

            negative_count = negative_count + (col_size - (curr_col + 1));
        }

        return negative_count;
    }
}