/*
311. Sparse Matrix Multiplication
Medium
956
333
company
Bloomberg
company
Facebook
company
Apple

Given two sparse matrices mat1 of size m x k and mat2 of size k x n, return the result of mat1 x mat2. You may assume that multiplication is always possible.

 

Example 1:

Input: mat1 = [[1,0,0],[-1,0,3]], mat2 = [[7,0,0],[0,0,0],[0,0,1]]
Output: [[7,0,0],[-7,0,3]]

Example 2:

Input: mat1 = [[0]], mat2 = [[0]]
Output: [[0]]

 

Constraints:

    m == mat1.length
    k == mat1[i].length == mat2.length
    n == mat2[i].length
    1 <= m, n, k <= 100
    -100 <= mat1[i][j], mat2[i][j] <= 100

Accepted
170.3K
Submissions
253K
Acceptance Rate
67.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (3)
Related Topics
Array
Hash Table
Matrix

*/
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size();
        int k = mat2.size();
        int n = mat2[0].size();
        vector<vector<int>> ans (m, vector<int>(n, 0));
        for(int row=0; row<m; row++)
            for(int ele=0; ele<k; ele++)
                if(mat1[row][ele] != 0)
                    for(int col=0; col<n; col++)
                        ans[row][col] += mat1[row][ele] * mat2[ele][col];
        return ans;        
    }
};