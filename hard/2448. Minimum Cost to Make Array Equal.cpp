/*
2448. Minimum Cost to Make Array Equal
Hard
2.1K
28
company
Google
company
Amazon
company
Cisco

You are given two 0-indexed arrays nums and cost consisting each of n positive integers.

You can do the following operation any number of times:

    Increase or decrease any element of the array nums by 1.

The cost of doing one operation on the ith element is cost[i].

Return the minimum total cost such that all the elements of the array nums become equal.

 

Example 1:

Input: nums = [1,3,5,2], cost = [2,3,1,14]
Output: 8
Explanation: We can make all the elements equal to 2 in the following way:
- Increase the 0th element one time. The cost is 2.
- Decrease the 1st element one time. The cost is 3.
- Decrease the 2nd element three times. The cost is 1 + 1 + 1 = 3.
The total cost is 2 + 3 + 3 = 8.
It can be shown that we cannot make the array equal with a smaller cost.

Example 2:

Input: nums = [2,2,2,2,2], cost = [4,2,8,1,3]
Output: 0
Explanation: All the elements are already equal, so no operations are needed.

 

Constraints:

    n == nums.length == cost.length
    1 <= n <= 105
    1 <= nums[i], cost[i] <= 106
    Test cases are generated in a way that the output doesn't exceed 253-1

Accepted
56.7K
Submissions
122.4K
Acceptance Rate
46.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (77)
Similar Questions
Minimum Moves to Equal Array Elements II
Medium
Maximum Product of the Length of Two Palindromic Substrings
Hard
Minimum Amount of Time to Fill Cups
Easy
Minimum Operations to Make All Array Elements Equal
Medium
Related Topics
Array
Binary Search
Greedy
Sorting
Prefix Sum
*/
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<vector<int>> numsAndCost(n, vector<int>(2));

        for (int i = 0; i < n; ++i) 
        {
            numsAndCost[i][0] = nums[i];
            numsAndCost[i][1] = cost[i];
        }
        sort(numsAndCost.begin(), numsAndCost.end());

        vector<long> prefixCost(n);
        prefixCost[0] = numsAndCost[0][1];
        
        for (int i = 1; i < n; ++i)
            prefixCost[i] = numsAndCost[i][1] + prefixCost[i - 1];

        long totalCost = 0l;
  
        for (int i = 1; i < n; ++i)
        {
            totalCost += 1l * numsAndCost[i][1] * (numsAndCost[i][0] - numsAndCost[0][0]);
            cout << endl << i << " " << totalCost;
        }
        
        long answer = totalCost;
  
        for (int i = 1; i < n; ++i) 
        {
            int gap = numsAndCost[i][0] - numsAndCost[i - 1][0];
            totalCost += 1l * prefixCost[i - 1] * gap;
            totalCost -= 1l * (prefixCost[n - 1] - prefixCost[i - 1]) * gap;
            answer = min(answer, totalCost);
        }
        
        return answer;
    }
};