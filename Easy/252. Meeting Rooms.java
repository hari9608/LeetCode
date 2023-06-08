/*
252. Meeting Rooms
Easy
1.8K
89
company
Google
company
Bloomberg
company
Amazon

Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: false

Example 2:

Input: intervals = [[7,10],[2,4]]
Output: true

 

Constraints:

    0 <= intervals.length <= 104
    intervals[i].length == 2
    0 <= starti < endi <= 106

Accepted
343.8K
Submissions
599.3K
Acceptance Rate
57.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (3)
Similar Questions
Merge Intervals
Medium
Meeting Rooms II
Medium
Meeting Rooms III
Hard
Related Topics
Array
Sorting
*/
class Solution {
    public boolean canAttendMeetings(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        for(int i = 0; i < intervals.length - 1; i++)
            if(intervals[i][1] > intervals[i + 1][0])
                return false;

        return true;
    }
}