/*
59. Spiral Matrix II
Medium
5.7K
234
company
Amazon
company
TikTok
company
Apple

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

 

Example 1:

Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:

Input: n = 1
Output: [[1]]

 

Constraints:

    1 <= n <= 20

Accepted
497.1K
Submissions
713.4K
Acceptance Rate
69.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (45)
Similar Questions
Spiral Matrix
Medium
Spiral Matrix III
Medium
Spiral Matrix IV
Medium
Related Topics
Array
Matrix
Simulation
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> generate_matrix(n, vector<int>(n));
        int left = 0;
        int top = 0;
        int right = n - 1;
        int bottom = n - 1;
        int val = 1;
        int i;
        
        while (left <= right && top <= bottom) 
        {
            for (i = left; i <= right; i++)     generate_matrix[top][i] = val++;        
            top++;
            
            for (i = top; i <= bottom; i++)     generate_matrix[i][right] = val++;      
            right--;
            
            if (top <= bottom) 
            { 
                for (i = right; i >= left; i--) generate_matrix[bottom][i] = val++;     
                bottom--;
            }
            
            if (left <= right)
            {                                                                        
                for (i = bottom; i >= top; i--) generate_matrix[i][left] = val++;       
                left++;
            }
        }
        
        return generate_matrix;
    }
};