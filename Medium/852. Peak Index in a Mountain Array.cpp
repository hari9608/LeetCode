/*
852. Peak Index in a Mountain Array
Medium
5.2K
1.8K
company
Amazon
company
Adobe
company
Bloomberg

An array arr a mountain if the following properties hold:

    arr.length >= 3
    There exists some i with 0 < i < arr.length - 1 such that:
        arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
        arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

You must solve it in O(log(arr.length)) time complexity.

 

Example 1:

Input: arr = [0,1,0]
Output: 1

Example 2:

Input: arr = [0,2,1,0]
Output: 1

Example 3:

Input: arr = [0,10,5,2]
Output: 1

 

Constraints:

    3 <= arr.length <= 105
    0 <= arr[i] <= 106
    arr is guaranteed to be a mountain array.

Accepted
561K
Submissions
814.3K
Acceptance Rate
68.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (62)
Similar Questions
Find Peak Element
Medium
Find in Mountain Array
Hard
Minimum Number of Removals to Make Mountain Array
Hard
Related Topics
Array
Binary Search
*/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size();
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(arr[mid] < arr[mid + 1])     left = mid + 1;
            else                            right = mid;
        }

        return left;
    }
};