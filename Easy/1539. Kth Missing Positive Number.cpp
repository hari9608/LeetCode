/*
1539. Kth Missing Positive Number
Easy
5.4K
344
company
Facebook
company
Adobe
company
Amazon

Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

 

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.

 

Constraints:

    1 <= arr.length <= 1000
    1 <= arr[i] <= 1000
    1 <= k <= 1000
    arr[i] < arr[j] for 1 <= i < j <= arr.length

 

Follow up:

Could you solve this problem in less than O(n) complexity?
Accepted
308.5K
Submissions
526.5K
Acceptance Rate
58.6%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (54)
Similar Questions
Append K Integers With Minimal Sum
Medium
Related Topics
Array
Binary Search
*/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0;
        int end = arr.size() - 1;
        while(start <= end)
        {
            int mid = (start + end) / 2;
            if(arr[mid] - mid - 1 < k)      start = mid+1;
            else                            end = mid-1;
        }

        return start + k;
    }
};