/*
118. Pascal's Triangle
Easy
10.2K
328
company
Amazon
company
Adobe
company
Apple

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:

Input: numRows = 1
Output: [[1]]

 

Constraints:

    1 <= numRows <= 30

Accepted
1.2M
Submissions
1.7M
Acceptance Rate
71.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (40)
Similar Questions
Pascal's Triangle II
Easy
Related Topics
Array
Dynamic Programming
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> generate;

        vector<int> o(1,1);
        generate.push_back(o);

        for(int row = 1; row < numRows; row++)
        {
            vector<int> insert(1, 1);

            for(int col = 1; col < row; col++)
                insert.push_back(generate[row - 1][col - 1] + generate[row - 1][col]);

            insert.push_back(1);
            
            generate.push_back(insert);
        }

        return generate;
    }
};