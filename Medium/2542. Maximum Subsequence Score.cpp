/*
2542. Maximum Subsequence Score
Medium
2K
87
company
Amazon
DE Shaw

You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. You must choose a subsequence of indices from nums1 of length k.

For chosen indices i0, i1, ..., ik - 1, your score is defined as:

    The sum of the selected elements from nums1 multiplied with the minimum of the selected elements from nums2.
    It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).

Return the maximum possible score.

A subsequence of indices of an array is a set that can be derived from the set {0, 1, ..., n-1} by deleting some or no elements.

 

Example 1:

Input: nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
Output: 12
Explanation: 
The four possible subsequence scores are:
- We choose the indices 0, 1, and 2 with score = (1+3+3) * min(2,1,3) = 7.
- We choose the indices 0, 1, and 3 with score = (1+3+2) * min(2,1,4) = 6. 
- We choose the indices 0, 2, and 3 with score = (1+3+2) * min(2,3,4) = 12. 
- We choose the indices 1, 2, and 3 with score = (3+3+2) * min(1,3,4) = 8.
Therefore, we return the max score, which is 12.

Example 2:

Input: nums1 = [4,2,3,1,1], nums2 = [7,5,10,9,6], k = 1
Output: 30
Explanation: 
Choosing index 2 is optimal: nums1[2] * nums2[2] = 3 * 10 = 30 is the maximum possible score.

 

Constraints:

    n == nums1.length == nums2.length
    1 <= n <= 105
    0 <= nums1[i], nums2[j] <= 105
    1 <= k <= n

Accepted
52K
Submissions
92.4K
Acceptance Rate
56.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (41)
Similar Questions
IPO
Hard
Minimum Cost to Hire K Workers
Hard
Related Topics
Array
Greedy
Sorting
Heap (Priority Queue)
*/
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> score;

        for(int i=0;i<nums1.size();i++)
            score.push_back({nums2[i],nums1[i]});

        sort(score.rbegin(), score.rend());

        long long max_score = 0;
        long long score_sum = 0;

        priority_queue<int,vector<int>,greater<int>> top_k_score;

        for(int i=0;i<k-1;i++)
        {
            score_sum += score[i].second;
            top_k_score.push(score[i].second);
        }

        for(int i = k-1;i<nums1.size();i++)
        {
            score_sum += score[i].second;
            top_k_score.push(score[i].second);
            
            max_score = max(max_score,score_sum*score[i].first);

            score_sum -= top_k_score.top();
            top_k_score.pop();
        }

        return max_score;    
    }
};