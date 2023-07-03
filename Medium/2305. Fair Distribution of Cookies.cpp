/*
2305. Fair Distribution of Cookies
Medium
1.8K
75
company
Amazon

You are given an integer array cookies, where cookies[i] denotes the number of cookies in the ith bag. You are also given an integer k that denotes the number of children to distribute all the bags of cookies to. All the cookies in the same bag must go to the same child and cannot be split up.

The unfairness of a distribution is defined as the maximum total cookies obtained by a single child in the distribution.

Return the minimum unfairness of all distributions.

 

Example 1:

Input: cookies = [8,15,10,20,8], k = 2
Output: 31
Explanation: One optimal distribution is [8,15,8] and [10,20]
- The 1st child receives [8,15,8] which has a total of 8 + 15 + 8 = 31 cookies.
- The 2nd child receives [10,20] which has a total of 10 + 20 = 30 cookies.
The unfairness of the distribution is max(31,30) = 31.
It can be shown that there is no distribution with an unfairness less than 31.

Example 2:

Input: cookies = [6,1,3,2,2,4,1,2], k = 3
Output: 7
Explanation: One optimal distribution is [6,1], [3,2,2], and [4,1,2]
- The 1st child receives [6,1] which has a total of 6 + 1 = 7 cookies.
- The 2nd child receives [3,2,2] which has a total of 3 + 2 + 2 = 7 cookies.
- The 3rd child receives [4,1,2] which has a total of 4 + 1 + 2 = 7 cookies.
The unfairness of the distribution is max(7,7,7) = 7.
It can be shown that there is no distribution with an unfairness less than 7.

 

Constraints:

    2 <= cookies.length <= 8
    1 <= cookies[i] <= 105
    2 <= k <= cookies.length

Accepted
54.3K
Submissions
79.2K
Acceptance Rate
68.6%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (59)
Similar Questions
Split Array Largest Sum
Hard
Split Array with Equal Sum
Hard
Partition to K Equal Sum Subsets
Medium
Minimum XOR Sum of Two Arrays
Hard
The Number of Good Subsets
Hard
Minimum Number of Work Sessions to Finish the Tasks
Medium
Partition Array Into Two Arrays to Minimize Sum Difference
Hard
Maximum Rows Covered by Columns
Medium
Distribute Money to Maximum Children
Easy
Related Topics
Array
Dynamic Programming
Backtracking
Bit Manipulation
Bitmask
*/
class Solution {
public:
    void backtrack(int ind, vector<int>& cookies, vector<int> child, int k, int &res)
    {
        if(cookies.size() == ind)
        {
            res = min(res, *max_element(child.begin(), child.end()));
            return;
        }

        for(int i = 0; i < k; i++)
        {
            if(i > 0 && child[i] == child[i - 1])
                continue;

            if(child[i] + cookies[ind] > res)
                continue;

            child[i] += cookies[ind];
            backtrack(ind + 1, cookies, child, k, res);

            child[i] -= cookies[ind];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int distribute_cookies = INT_MAX;
        vector<int> child(k, 0);
        
        sort(cookies.begin(), cookies.end());
        backtrack(0, cookies, child, k, distribute_cookies);

        return distribute_cookies;
    }
};