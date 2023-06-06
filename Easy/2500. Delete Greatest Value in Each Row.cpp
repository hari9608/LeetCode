/*
2500. Delete Greatest Value in Each Row
Easy
395
23

You are given an m x n matrix grid consisting of positive integers.

Perform the following operation until grid becomes empty:

    Delete the element with the greatest value from each row. If multiple such elements exist, delete any of them.
    Add the maximum of deleted elements to the answer.

Note that the number of columns decreases by one after each operation.

Return the answer after performing the operations described above.

 

Example 1:

Input: grid = [[1,2,4],[3,3,1]]
Output: 8
Explanation: The diagram above shows the removed values in each step.
- In the first operation, we remove 4 from the first row and 3 from the second row (notice that, there are two cells with value 3 and we can remove any of them). We add 4 to the answer.
- In the second operation, we remove 2 from the first row and 3 from the second row. We add 3 to the answer.
- In the third operation, we remove 1 from the first row and 1 from the second row. We add 1 to the answer.
The final answer = 4 + 3 + 1 = 8.

Example 2:

Input: grid = [[10]]
Output: 10
Explanation: The diagram above shows the removed values in each step.
- In the first operation, we remove 10 from the first row. We add 10 to the answer.
The final answer = 10.

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 50
    1 <= grid[i][j] <= 100

Accepted
34K
Submissions
42.5K
Acceptance Rate
80.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (9)
Similar Questions
Equal Row and Column Pairs
Medium
Related Topics
Array
Sorting
Matrix
*/
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();     
        vector<priority_queue<int>> rows_queue(m);
        
        for(int i=0; i<m; i++)
            for(auto val : grid[i])     rows_queue[i].push(val);

        int deleted_greatest_value = 0;
        for(int in=0; in<n; in++)
        {
            int greatest = INT_MIN;
            for(int i=0; i<m; i++)
            {
                greatest = max(greatest, rows_queue[i].top());
                rows_queue[i].pop();
            }
            deleted_greatest_value += greatest;
        }

        return deleted_greatest_value;
    }
};