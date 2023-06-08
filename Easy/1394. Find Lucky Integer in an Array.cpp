/*
1394. Find Lucky Integer in an Array
Easy
976
26
company
Apple
Oracle
company
Microsoft

Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

Return the largest lucky integer in the array. If there is no lucky integer return -1.

 

Example 1:

Input: arr = [2,2,3,4]
Output: 2
Explanation: The only lucky number in the array is 2 because frequency[2] == 2.

Example 2:

Input: arr = [1,2,2,3,3,3]
Output: 3
Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.

Example 3:

Input: arr = [2,2,2,3,3]
Output: -1
Explanation: There are no lucky numbers in the array.

 

Constraints:

    1 <= arr.length <= 500
    1 <= arr[i] <= 500

Accepted
96.2K
Submissions
148.5K
Acceptance Rate
64.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (3)
Related Topics
Array
Hash Table
Counting
*/

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int fre[501] = {0};
        int max=1;
        for(int i=0; i<arr.size(); i++){
            max = arr[i]>max?arr[i]:max;
            fre[arr[i]]++;
        }
        while(max>0){
          //  cout << fre[max] << " " << max << " ";
            if(fre[max]==max) return max;
            max--;
        }
        return -1;
    }
};