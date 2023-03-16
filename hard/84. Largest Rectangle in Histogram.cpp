/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:

Input: heights = [2,4]
Output: 4

 

Constraints:

    1 <= heights.length <= 105
    0 <= heights[i] <= 104

*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        stack<int> st;
        int laefSmall[len], rightSmall[len];
        for(int i=0; i<len; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) laefSmall[i] = 0;
            else laefSmall[i] = st.top()+1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=len-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) rightSmall[i] = len-1;
            else rightSmall[i] = st.top()-1;
            st.push(i);
        }
        int res=0;
        for(int i=0; i<len; i++){
            res = max(res, heights[i]*(rightSmall[i]-laefSmall[i]+1));
        }

        return res;        
    }
};