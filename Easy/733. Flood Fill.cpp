/*
733. Flood Fill
Easy
7.3K
719
company
Amazon
company
Microsoft
company
Apple

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

 

Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation: The starting pixel is already colored 0, so no changes are made to the image.

 

Constraints:

    m == image.length
    n == image[i].length
    1 <= m, n <= 50
    0 <= image[i][j], color < 216
    0 <= sr < m
    0 <= sc < n

Accepted
730.6K
Submissions
1.2M
Acceptance Rate
62.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (70)
Similar Questions
Island Perimeter
Easy
Related Topics
Array
Depth-First Search
Breadth-First Search
Matrix
*/
class Solution {
public:
    void fillColor(vector<vector<int>>& image, int r, int c, int curr_col, int color)
    {
        if (image[r][c] == curr_col) 
        {
            image[r][c] = color;
            if (r >= 1)                 fillColor(image, r-1, c, curr_col, color);
            if (c >= 1)                 fillColor(image, r, c-1, curr_col, color);
            if (r+1 < image.size())     fillColor(image, r+1, c, curr_col, color);
            if (c+1 < image[0].size())  fillColor(image, r, c+1, curr_col, color);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int curr_col = image[sr][sc];
        if (color != curr_col)  fillColor(image, sr, sc, curr_col, color);
        return image;
    }
};