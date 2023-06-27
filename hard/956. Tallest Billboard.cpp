/*
956. Tallest Billboard
Hard
2.1K
51

You are installing a billboard and want it to have the largest height. The billboard will have two steel supports, one on each side. Each steel support must be an equal height.

You are given a collection of rods that can be welded together. For example, if you have rods of lengths 1, 2, and 3, you can weld them together to make a support of length 6.

Return the largest possible height of your billboard installation. If you cannot support the billboard, return 0.

 

Example 1:

Input: rods = [1,2,3,6]
Output: 6
Explanation: We have two disjoint subsets {1,2,3} and {6}, which have the same sum = 6.

Example 2:

Input: rods = [1,2,3,4,5,6]
Output: 10
Explanation: We have two disjoint subsets {2,3,5} and {4,6}, which have the same sum = 10.

Example 3:

Input: rods = [1,2]
Output: 0
Explanation: The billboard cannot be supported, so we return 0.

 

Constraints:

    1 <= rods.length <= 20
    1 <= rods[i] <= 1000
    sum(rods[i]) <= 5000

Accepted
52K
Submissions
98.3K
Acceptance Rate
52.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (64)
Similar Questions
Partition Array Into Two Arrays to Minimize Sum Difference
Hard
Related Topics
Array
Dynamic Programming
*/
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        map<int, int> dp;
        dp[0] = 0;
        
        for (int r : rods) 
        {
            map<int, int> newDp(dp);
            
            for (auto entry : dp) 
            {
                int diff = entry.first;
                int taller = entry.second;
                int shorter = taller - diff;

                int newTaller = newDp[diff + r];
                newDp[diff + r] = max(newTaller, taller + r);
                
                int newDiff = abs(shorter + r - taller);
                int newTaller2 = max(shorter + r, taller);
                newDp[newDiff] = max(newTaller2, newDp[newDiff]);
            }
            
            dp = newDp;
        }
        
        return dp[0];
    }
};