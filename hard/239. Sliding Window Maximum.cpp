/*
239. Sliding Window Maximum
Hard
16.7K
561
company
Amazon
company
Microsoft
company
Uber

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:

Input: nums = [1], k = 1
Output: [1]

 

Constraints:

    1 <= nums.length <= 105
    -104 <= nums[i] <= 104
    1 <= k <= nums.length

Accepted
870.5K
Submissions
1.9M
Acceptance Rate
46.6%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (97)
Similar Questions
Minimum Window Substring
Hard
Min Stack
Medium
Longest Substring with At Most Two Distinct Characters
Medium
Paint House II
Hard
Jump Game VI
Medium
Maximum Number of Robots Within Budget
Hard
Maximum Tastiness of Candy Basket
Medium
Maximal Score After Applying K Operations
Medium
Related Topics
Array
Queue
Sliding Window
Heap (Priority Queue)
Monotonic Queue
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        deque<int> dq;
        vector<int> res;

        for (int i = 0; i < k; i++) 
        {
            while (!dq.empty() && nums[i] >= nums[dq.back()]) 
                dq.pop_back();

            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);

        for (int i = k; i < nums.size(); i++) 
        {
            if(dq.front() == i - k) 
                dq.pop_front();
            
            while (!dq.empty() && nums[i] >= nums[dq.back()]) 
                dq.pop_back();

            dq.push_back(i);
            res.push_back(nums[dq.front()]);
        }
        
        return res;
    }
};