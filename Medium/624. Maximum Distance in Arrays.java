/*
624. Maximum Distance in Arrays
Medium
658
65
company
Yahoo

You are given m arrays, where each array is sorted in ascending order.

You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.

Return the maximum distance.

 

Example 1:

Input: arrays = [[1,2,3],[4,5],[1,2,3]]
Output: 4
Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.

Example 2:

Input: arrays = [[1],[1]]
Output: 0

 

Constraints:

    m == arrays.length
    2 <= m <= 105
    1 <= arrays[i].length <= 500
    -104 <= arrays[i][j] <= 104
    arrays[i] is sorted in ascending order.
    There will be at most 105 integers in all the arrays.

Accepted
38.9K
Submissions
93.5K
Acceptance Rate
41.6%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (1)
Related Topics
Array
Greedy
*/
class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        int max_distance = 0;
        int n = arrays.get(0).size();
        int min_val = arrays.get(0).get(0);
        int max_val = arrays.get(0).get(n - 1);

        for(int i = 1; i < arrays.size(); i++)
        {
            n = arrays.get(i).size();
            max_distance = Math.max(max_distance, 
                        Math.max(Math.abs(arrays.get(i).get(n - 1) - min_val), 
                                 Math.abs(max_val - arrays.get(i).get(0))));
            min_val = Math.min(min_val, arrays.get(i).get(0));
            max_val = Math.max(max_val, arrays.get(i).get(n - 1));
        }

        return max_distance;
    }
}