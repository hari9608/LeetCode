/*
1346. Check If N and Its Double Exist
Easy
1.7K
176
company
Amazon
company
Google

Given an array arr of integers, check if there exist two indices i and j such that :

    i != j
    0 <= i, j < arr.length
    arr[i] == 2 * arr[j]

 

Example 1:

Input: arr = [10,2,5,3]
Output: true
Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]

Example 2:

Input: arr = [3,1,7,11]
Output: false
Explanation: There is no i and j that satisfy the conditions.

 

Constraints:

    2 <= arr.length <= 500
    -103 <= arr[i] <= 103

Accepted
287.8K
Submissions
785.9K
Acceptance Rate
36.6%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (16)
Similar Questions
Keep Multiplying Found Values by Two
Easy
Related Topics
Array
Hash Table
Two Pointers
Binary Search
Sorting
*/
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());

        for(int i = 0; i < arr.size(); i++)
        {
            int start = 0;
            int end = arr.size()-1;
            int target = 2 * arr[i];
            while(start <= end)
            {
                int mid = start + (end - start) / 2;
                if((arr[mid] == target) && (i != mid))
                    return true;
                else if(arr[mid] > target)
                    end = mid - 1;
                else   
                    start = mid + 1;
            }
        }

        return false;
    }
};