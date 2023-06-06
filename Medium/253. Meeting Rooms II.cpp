/*
253. Meeting Rooms II
Medium
6.5K
137
company
Bloomberg
company
Google
company
Amazon

Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2

Example 2:

Input: intervals = [[7,10],[2,4]]
Output: 1

 

Constraints:

    1 <= intervals.length <= 104
    0 <= starti < endi <= 106

Accepted
784.3K
Submissions
1.5M
Acceptance Rate
50.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (18)
Similar Questions
Merge Intervals
Medium
Meeting Rooms
Easy
Minimum Number of Arrows to Burst Balloons
Medium
Car Pooling
Medium
Number of Flowers in Full Bloom
Hard
Meeting Rooms III
Hard
Total Cost to Hire K Workers
Medium
Related Topics
Array
Two Pointers
Greedy
Sorting
Heap (Priority Queue)
Prefix Sum
*/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> meeting_ends;

        for(auto interval : intervals)
        {
            if(!meeting_ends.empty() && meeting_ends.top() <= interval[0])
                meeting_ends.pop();
                
            meeting_ends.push(interval[1]);
        }

        return meeting_ends.size();
    }
};