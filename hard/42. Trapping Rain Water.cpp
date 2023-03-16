/*
42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9

 

Constraints:

    n == height.length
    1 <= n <= 2 * 104
    0 <= height[i] <= 105

*/

class Solution {
public:
    int trap(vector<int>& height) {
        int st = 0;
        int en = height.size() - 1;
        int maxL = 0;
        int maxR = 0;
        int res = 0;
        while(st < en)
            if(height[st] <= height[en])
                if(height[st] > maxL)   maxL = height[st++];
                else res += maxL - height[st++];
            else
                if(height[en] > maxR)   maxR = height[en--];
                else res += maxR - height[en--];
        return res;
    }
};