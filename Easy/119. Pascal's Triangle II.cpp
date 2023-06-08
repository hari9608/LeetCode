/*
119. Pascal's Triangle II
Easy
3.8K
303
company
Amazon
company
Goldman Sachs
company
Microsoft

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

 

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]

Example 2:

Input: rowIndex = 0
Output: [1]

Example 3:

Input: rowIndex = 1
Output: [1,1]

 

Constraints:

    0 <= rowIndex <= 33

 

Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?
Accepted
684.9K
Submissions
1.1M
Acceptance Rate
61.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (16)
Similar Questions
Pascal's Triangle
Easy
Find Triangular Sum of an Array
Medium
Related Topics
Array
Dynamic Programming
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> getRow(rowIndex + 1, 1);
        
        for (int i = 1; i < rowIndex; i++)
            for (int j = i; j > 0; j--)
                getRow[j] += getRow[j - 1];
        
        return getRow;
    }
};