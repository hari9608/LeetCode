/*
1213. Intersection of Three Sorted Arrays
Easy
545
24
company
Facebook

Given three integer arrays arr1, arr2 and arr3 sorted in strictly increasing order, return a sorted array of only the integers that appeared in all three arrays.

 

Example 1:

Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
Output: [1,5]
Explanation: Only 1 and 5 appeared in the three arrays.

Example 2:

Input: arr1 = [197,418,523,876,1356], arr2 = [501,880,1593,1710,1870], arr3 = [521,682,1337,1395,1764]
Output: []

 

Constraints:

    1 <= arr1.length, arr2.length, arr3.length <= 1000
    1 <= arr1[i], arr2[i], arr3[i] <= 2000

Accepted
78.2K
Submissions
97.9K
Acceptance Rate
79.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (2)
Similar Questions
Intersection of Two Arrays
Easy
Intersection of Multiple Arrays
Easy
Related Topics
Array
Hash Table
Binary Search
Counting
*/
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        map<int, int> intersection;
        vector<int> arrays_intersection;

        for(auto arr : arr1)    intersection[arr]++;
        for(auto arr : arr2)    intersection[arr]++;
        for(auto arr : arr3)    intersection[arr]++;
        for(auto count : intersection)  
            if(count.second == 3)       arrays_intersection.push_back(count.first);
            
        return arrays_intersection;
    }
};