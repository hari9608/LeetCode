/*
1732. Find the Highest Altitude
Easy
1.4K
123
company
Apple

There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.

 

Example 1:

Input: gain = [-5,1,5,0,-7]
Output: 1
Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.

Example 2:

Input: gain = [-4,-3,-2,-1,4,3,2]
Output: 0
Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.

 

Constraints:

    n == gain.length
    1 <= n <= 100
    -100 <= gain[i] <= 100

Accepted
123.7K
Submissions
155.9K
Acceptance Rate
79.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (17)
Related Topics
Array
Prefix Sum
*/
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int largest_altitude = 0;
        int sum =0;
        
        for(int g=0; g<gain.size(); g++)
        {
            sum += gain[g];
            largest_altitude = max(largest_altitude, sum);
        }

        return largest_altitude;
    }
};