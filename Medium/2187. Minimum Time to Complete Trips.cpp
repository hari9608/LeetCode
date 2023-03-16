/*
2187. Minimum Time to Complete Trips
Medium
2.4K
149
company
Uber
company
Google
company
Amazon

You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.

Each bus can make multiple trips successively; that is, the next trip can start immediately after completing the current trip. Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.

You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. Return the minimum time required for all buses to complete at least totalTrips trips.

 

Example 1:

Input: time = [1,2,3], totalTrips = 5
Output: 3
Explanation:
- At time t = 1, the number of trips completed by each bus are [1,0,0]. 
  The total number of trips completed is 1 + 0 + 0 = 1.
- At time t = 2, the number of trips completed by each bus are [2,1,0]. 
  The total number of trips completed is 2 + 1 + 0 = 3.
- At time t = 3, the number of trips completed by each bus are [3,1,1]. 
  The total number of trips completed is 3 + 1 + 1 = 5.
So the minimum time needed for all buses to complete at least 5 trips is 3.

Example 2:

Input: time = [2], totalTrips = 1
Output: 2
Explanation:
There is only one bus, and it will complete its first trip at t = 2.
So the minimum time needed to complete 1 trip is 2.

 

Constraints:

    1 <= time.length <= 105
    1 <= time[i], totalTrips <= 107

Accepted
93.2K
Submissions
237.8K
Acceptance Rate
39.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (61)
Similar Questions
Maximum Candies Allocated to K Children
Medium
Minimum Speed to Arrive on Time
Medium
Minimized Maximum of Products Distributed to Any Store
Medium
Maximum Running Time of N Computers
Hard
Maximum Number of Robots Within Budget
Hard
Minimize Maximum of Array
Medium
Related Topics
Array
Binary Search

*/
class Solution {
public:
    bool canFinish(vector<int>& time, long long avg_time, int totalTrips)
    {
        long long trips = 0;
        for(int t : time)
            trips += avg_time / t;
        return trips >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long min_time = 1;
        long long max_time = 1LL * totalTrips * *max_element(time.begin(), time.end());

        while(min_time < max_time)
        {
            long long avg_time = (min_time + max_time) / 2;
            if(canFinish(time, avg_time, totalTrips))   
                max_time = avg_time;
            else 
                min_time = avg_time+1; 
        }
        return min_time;
    }
};