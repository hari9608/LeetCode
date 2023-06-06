/*
1014. Best Sightseeing Pair
Medium
2.3K
54
company
Google
company
Wayfair

You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.

 

Example 1:

Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11

Example 2:

Input: values = [1,2]
Output: 2

 

Constraints:

    2 <= values.length <= 5 * 104
    1 <= values[i] <= 1000

Accepted
85.5K
Submissions
144.1K
Acceptance Rate
59.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (7)
Related Topics
Array
Dynamic Programming
*/
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxi = values[0];
        int max_score_sightseeing_pair = INT_MIN;

        for(int i = 1; i < values.size(); i++)
        {
            max_score_sightseeing_pair = max(max_score_sightseeing_pair, maxi + values[i] - i);
            maxi = max(maxi, values[i] + i);
        } 

        return max_score_sightseeing_pair;
    }
};