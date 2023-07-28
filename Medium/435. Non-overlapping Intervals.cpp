/*
435. Non-overlapping Intervals
Medium
7.3K
189
JPMorgan
company
Facebook
company
Amazon

Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

 

Constraints:

    1 <= intervals.length <= 105
    intervals[i].length == 2
    -5 * 104 <= starti < endi <= 5 * 104

Accepted
441.1K
Submissions
849.4K
Acceptance Rate
51.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (53)
Similar Questions
Minimum Number of Arrows to Burst Balloons
Medium
Determine if Two Events Have Conflict
Easy
Related Topics
Array
Dynamic Programming
Greedy
Sorting
*/
bool compareSecondElement(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compareSecondElement);
        int overlap_intervals = 0;
        int k = INT_MIN;
        
        for (int i = 0; i < intervals.size(); i++) 
        {
            int x = intervals[i][0];
            int y = intervals[i][1];
            
            if (x >= k) 
                k = y;
            else 
                overlap_intervals++;
        }
        
        return overlap_intervals;
    }
};