/*
1232. Check If It Is a Straight Line
Easy
2.3K
241
company
Palantir Technologies

You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

 

 

Example 1:

Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Example 2:

Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false

 

Constraints:

    2 <= coordinates.length <= 1000
    coordinates[i].length == 2
    -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
    coordinates contains no duplicate point.

Accepted
217K
Submissions
525.6K
Acceptance Rate
41.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (42)
Related Topics
Array
Math
Geometry
*/
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int no_coordinates = coordinates.size();

        if(no_coordinates == 1 || no_coordinates == 2)  
            return true;

        sort(coordinates.begin(), coordinates.end());

        double slope = (double)(coordinates[1][1] - coordinates[0][1]) / (double)(coordinates[1][0] - coordinates[0][0]);
        
        for(int i = 0; i < no_coordinates - 1; i++)
        {
            double curr = (double)(coordinates[i + 1][1] - coordinates[i][1]) / (double)(coordinates[i + 1][0] - coordinates[i][0]);
            
            if(abs(slope) != abs(curr))     
                return false;
        }

        return true;
    }
};