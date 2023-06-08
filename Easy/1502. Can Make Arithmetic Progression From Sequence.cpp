/*
1502. Can Make Arithmetic Progression From Sequence
Easy
2K
96
company
Amazon

A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.

 

Example 1:

Input: arr = [3,5,1]
Output: true
Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.

Example 2:

Input: arr = [1,2,4]
Output: false
Explanation: There is no way to reorder the elements to obtain an arithmetic progression.

 

Constraints:

    2 <= arr.length <= 1000
    -106 <= arr[i] <= 106

Accepted
207.4K
Submissions
294.3K
Acceptance Rate
70.5%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (41)
Similar Questions
Arithmetic Subarrays
Medium
Related Topics
Array
Sorting
*/
class Solution {
public:
    bool canMakeArithmeticProgression(std::vector<int>& arr) {
        int min_value = INT_MAX;
        int max_value = INT_MIN;
        int n = arr.size();

        for(int a : arr)
        {
            min_value = a < min_value ? a : min_value;
            max_value = a > max_value ? a : max_value;
        }
        
        if ((max_value - min_value) % (n - 1) != 0) 
            return false;
        
        int diff = (max_value - min_value) / (n - 1);
        int i = 0;
        
        while (i < n) 
        {
            if (arr[i] == min_value + i * diff) 
                i += 1;
                
            else if ((arr[i] - min_value) % diff != 0) 
                return false;
                
            else 
            {
                int j = (arr[i] - min_value) / diff;
                
                if (arr[i] == arr[j]) 
                    return false;
                    
                swap(arr[i], arr[j]);
            }
        }
        
        return true;
    }
};