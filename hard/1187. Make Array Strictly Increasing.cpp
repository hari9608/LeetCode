/*
1187. Make Array Strictly Increasing
Hard
2K
45

Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.

In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].

If there is no way to make arr1 strictly increasing, return -1.

 

Example 1:

Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
Output: 1
Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].

Example 2:

Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
Output: 2
Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].

Example 3:

Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
Output: -1
Explanation: You can't make arr1 strictly increasing.

 

Constraints:

    1 <= arr1.length, arr2.length <= 2000
    0 <= arr1[i], arr2[i] <= 10^9

 
Accepted
50.8K
Submissions
84.7K
Acceptance Rate
59.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (45)
Similar Questions
Make Array Non-decreasing or Non-increasing
Hard
Related Topics
Array
Binary Search
Dynamic Programming
Sorting
*/
class Solution {
private:
    int check(int curr, int left, vector<int>& arr1 ,vector<int>& arr2, vector<unordered_map<int,int>>& dp)
    {
        if (curr == arr1.size())
            return 0;

        if (dp[curr].find(left) != dp[curr].end())
            return dp[curr][left];

        int exclude;
        int include;

        if (arr1[curr] > left)    
            exclude = check(curr + 1, arr1[curr], arr1, arr2, dp);
        else
            exclude = INT_MAX;

        int rep = upper_bound(arr2.begin(), arr2.end(), left) - arr2.begin();

        if (rep == arr2.size())
            include = INT_MAX;
        else
            include = check(curr+1, arr2[rep], arr1, arr2, dp);

            if (include == INT_MAX)
                dp[curr][left] = exclude;
            else
                dp[curr][left] = min(exclude, include + 1);

        return dp[curr][left];
    }

public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        vector<unordered_map<int,int>> dp(2001);  

        int val = check(0, INT_MIN, arr1, arr2, dp);
        
        return val == INT_MAX ? -1 : val;
    }
};