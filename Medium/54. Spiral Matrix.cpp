/*
54. Spiral Matrix
Medium
10.7K
1K
company
Amazon
company
Microsoft
company
Cisco

Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

 

Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 10
    -100 <= matrix[i][j] <= 100

*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        vector<int> res;
        int left = 0;
        int top = 0;
        int right = colSize - 1;
        int bottom = rowSize - 1;
        int i;
        while (left <= right && top <= bottom) 
        {
            for (i = left; i <= right; i++)     res.push_back(matrix[top][i]);       top++;
            
            for (i = top; i <= bottom; i++)     res.push_back(matrix[i][right]);     right--;
            
            if (top <= bottom) 
            { 
                for (i = right; i >= left; i--) res.push_back(matrix[bottom][i]);    bottom--;
            }
            
            if (left <= right)
            {                                                                        
                for (i = bottom; i >= top; i--) res.push_back(matrix[i][left]);      left++;
            }
        }
        return res;
    }
};