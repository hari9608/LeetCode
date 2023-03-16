/*
1198. Find Smallest Common Element in All Rows
Medium
509
27
Walmart Global Tech
company
Intel
company
Microsoft

Given an m x n matrix mat where every row is sorted in strictly increasing order, return the smallest common element in all rows.

If there is no common element, return -1.

 

Example 1:

Input: mat = [[1,2,3,4,5],[2,4,5,8,10],[3,5,7,9,11],[1,3,5,7,9]]
Output: 5

Example 2:

Input: mat = [[1,2,3],[2,3,4],[2,3,5]]
Output: 2

 

Constraints:

    m == mat.length
    n == mat[i].length
    1 <= m, n <= 500
    1 <= mat[i][j] <= 104
    mat[i] is sorted in strictly increasing order.

Accepted
38.2K
Submissions
49.8K
Acceptance Rate
76.6%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (0)
Similar Questions
Intersection of Multiple Arrays
Easy
Related Topics
Array
Hash Table
Binary Search
Matrix
Counting
*/
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int num_len = mat.size();
        map<int, int> common;

        for(auto num : mat)    for(auto arr : num)    common[arr]++;
        
        for(auto count : common)  
            if(count.second == num_len)       
                return count.first;
            
        return -1;
    }
};
