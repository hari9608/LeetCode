/*
1010. Pairs of Songs With Total Durations Divisible by 60
Medium
3.8K
147
company
Paypal
company
Goldman Sachs
company
BlackRock

You are given a list of songs where the ith song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.

 

Example 1:

Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60

Example 2:

Input: time = [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.

 

Constraints:

    1 <= time.length <= 6 * 104
    1 <= time[i] <= 500

Accepted
236.6K
Submissions
448.2K
Acceptance Rate
52.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (7)
Similar Questions
Destroy Sequential Targets
Medium
Related Topics
Array
Hash Table
Counting

*/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> duration(60);
        int num_pairs_divisible_by_60 = 0;
        for(int t : time)
        {
            if(t % 60)  num_pairs_divisible_by_60 += duration[60 - t % 60];
            else        num_pairs_divisible_by_60 += duration[t % 60];
            duration[t % 60]++;
        }

        return num_pairs_divisible_by_60;
    }
};
