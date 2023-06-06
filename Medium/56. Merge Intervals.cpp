/*
56. Merge Intervals
Medium
19.2K
649
company
Amazon
company
Google
company
LinkedIn

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

 

Constraints:

    1 <= intervals.length <= 104
    intervals[i].length == 2
    0 <= starti <= endi <= 104

Accepted
1.9M
Submissions
4.1M
Acceptance Rate
46.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (49)
Similar Questions
Insert Interval
Medium
Meeting Rooms
Easy
Meeting Rooms II
Medium
Teemo Attacking
Easy
Add Bold Tag in String
Medium
Range Module
Hard
Employee Free Time
Hard
Partition Labels
Medium
Interval List Intersections
Medium
Amount of New Area Painted Each Day
Hard
Longest Substring of One Repeating Character
Hard
Count Integers in Intervals
Hard
Divide Intervals Into Minimum Number of Groups
Medium
Determine if Two Events Have Conflict
Easy
Count Ways to Group Overlapping Ranges
Medium
Related Topics
Array
Sorting
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merge;

        merge.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++)
        {
            if(merge.back()[1] >= intervals[i][0])
                merge.back()[1] = max(merge.back()[1], intervals[i][1]);
            else 
                merge.push_back(intervals[i]);
        }

        return merge;
    }
};