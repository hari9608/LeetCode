/*
373. Find K Pairs with Smallest Sums
Medium
5.2K
301
company
Amazon
company
Google
company
Microsoft

You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

 

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

Example 3:

Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [[1,3],[2,3]]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]

 

Constraints:

    1 <= nums1.length, nums2.length <= 105
    -109 <= nums1[i], nums2[i] <= 109
    nums1 and nums2 both are sorted in ascending order.
    1 <= k <= 104

Accepted
233K
Submissions
588.3K
Acceptance Rate
39.6%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (49)
Similar Questions
Kth Smallest Element in a Sorted Matrix
Medium
Find K-th Smallest Pair Distance
Hard
Kth Smallest Product of Two Sorted Arrays
Hard
Related Topics
Array
Heap (Priority Queue)
*/

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> k_smallest_pairs;
        
        int nums1_len = nums1.size();
        int nums2_len = nums2.size();

        set<pair<int, int>> visits;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        visits.insert({0, 0});
        pq.push({nums1[0] + nums2[0], {0, 0}});

        while(k-- && !pq.empty())
        {
            int ind1 = pq.top().second.first;
            int ind2 = pq.top().second.second;
            pq.pop();

            k_smallest_pairs.push_back({nums1[ind1], nums2[ind2]});
            
            if(ind1 + 1 < nums1_len && visits.find({ind1 + 1, ind2}) == visits.end())
            {
                visits.insert({ind1 + 1, ind2});
                pq.push({nums1[ind1 + 1] + nums2[ind2], {ind1 + 1, ind2}});
            }               
                
            if(ind2 + 1 < nums2_len && visits.find({ind1, ind2 + 1}) == visits.end())
            {
                visits.insert({ind1, ind2 + 1});
                pq.push({nums1[ind1] + nums2[ind2 + 1], {ind1, ind2 + 1}});
            }
        }

        return k_smallest_pairs;
    }
};