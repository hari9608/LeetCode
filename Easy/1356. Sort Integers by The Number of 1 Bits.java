/*
1356. Sort Integers by The Number of 1 Bits
Easy
1.7K
79
JPMorgan
company
Goldman Sachs
company
VMware

You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the array after sorting it.

 

Example 1:

Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]

Example 2:

Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
Output: [1,2,4,8,16,32,64,128,256,512,1024]
Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.

 

Constraints:

    1 <= arr.length <= 500
    0 <= arr[i] <= 104

Accepted
114.6K
Submissions
156.3K
Acceptance Rate
73.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (9)
Similar Questions
Find Subsequence of Length K With the Largest Sum
Easy
Related Topics
Array
Bit Manipulation
Sorting
Counting
*/
class Solution {
    public int[] sortByBits(int[] arr) {
        int n = arr.length;
        int[][] a = new int[n][2];

        for(int i = 0; i < n; i++)
        {
            a[i][0] = Integer.bitCount(arr[i]);
            a[i][1] = arr[i];
        }

        Arrays.sort(a, (x, y) -> 
            (x[0] == y[0]) ? (x[1] - y[1]) : (x[0] - y[0])
        );

        for(int i = 0; i < n; i++)  arr[i] = a[i][1];

        return arr;
    }
}