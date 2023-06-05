/*
213. House Robber II
Medium
8.1K
118
company
Google
company
TikTok
company
Adobe

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 3:

Input: nums = [1,2,3]
Output: 3

 

Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 1000

Accepted
567K
Submissions
1.4M
Acceptance Rate
41.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (19)
Similar Questions
House Robber
Medium
Paint House
Medium
Paint Fence
Medium
House Robber III
Medium
Non-negative Integers without Consecutive Ones
Hard
Coin Path
Hard
Related Topics
Array
Dynamic Programming
*/

class Solution {
public:
    int robbed(vector<int> &house, int begin, int end)
    {
        int h1 = 0;
        int h2 = 0;

        for(int h = begin; h <= end; h++)
        {
            int temp = h1;
            int current = house[h];
            h1 = max(current + h2 , h1);
            h2 = temp;
        }

        return h1;
    }

    int rob(vector<int>& houses) {
        int no_houses = houses.size();
        if(!no_houses)      return 0;

        if(no_houses == 1)  return houses[0];

        int house_one = robbed(houses, 0, no_houses - 2);
        int house_two = robbed(houses, 1, no_houses - 1);

        return max(house_one, house_two);
    }
};