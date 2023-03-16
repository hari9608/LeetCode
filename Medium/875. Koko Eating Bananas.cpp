/*
875. Koko Eating Bananas
Medium
7.3K
336
company
Google
company
Amazon
company
DoorDash

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30

Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23

 

Constraints:

    1 <= piles.length <= 104
    piles.length <= h <= 109
    1 <= piles[i] <= 109

Accepted
341.2K
Submissions
652.7K
Acceptance Rate
52.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (96)
Similar Questions
Minimize Max Distance to Gas Station
Hard
Maximum Candies Allocated to K Children
Medium
Minimized Maximum of Products Distributed to Any Store
Medium
Frog Jump II
Medium
Related Topics
Array
Binary Search

*/
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min = 1;
        int max = *max_element(piles.begin(), piles.end());

        while(min < max)
        {
            int mid = (min + max) / 2;
            int hour_taken = 0;
            for(auto pile:piles)
                hour_taken += (pile / mid) + (pile % mid != 0);
            
            if(hour_taken <= h)  max = mid;
            else min = mid+1;
        }
        
        return min;
    }
};