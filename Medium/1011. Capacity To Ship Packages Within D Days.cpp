/*
1011. Capacity To Ship Packages Within D Days
Medium
7.6K
168
company
Amazon
company
Facebook
company
TikTok

A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

 

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

Example 2:

Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4

Example 3:

Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1

 

Constraints:

    1 <= days <= weights.length <= 5 * 104
    1 <= weights[i] <= 500

Accepted
261K
Submissions
385.6K
Acceptance Rate
67.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (81)
Similar Questions
Split Array Largest Sum
Hard
Divide Chocolate
Hard
Cutting Ribbons
Medium
Minimized Maximum of Products Distributed to Any Store
Medium
Maximum Bags With Full Capacity of Rocks
Medium
Minimum Total Distance Traveled
Hard
Related Topics
Array
Binary Search

*/
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = 0;
        int right = 25000000;
        for (int w: weights)    left = max(left, w);
        while (left < right) {
            int mid = (left + right) / 2;
            int need = 1;
            int current_weight = 0;
            for (int i = 0; i < weights.size() && need <= D; current_weight += weights[i++])
                if (current_weight + weights[i] > mid)
                {
                    current_weight = 0;
                    need++;
                }
            if (need > D) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
