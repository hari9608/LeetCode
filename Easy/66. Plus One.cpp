/*
66. Plus One
Easy
7.4K
5K
company
Amazon
company
Google
company
Apple

You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].

 

Constraints:

    1 <= digits.length <= 100
    0 <= digits[i] <= 9
    digits does not contain any leading 0's.

Accepted
1.7M
Submissions
3.9M
Acceptance Rate
43.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (98)
Similar Questions
Multiply Strings
Medium
Add Binary
Easy
Plus One Linked List
Medium
Add to Array-Form of Integer
Easy
Minimum Operations to Reduce an Integer to 0
Medium
Related Topics
Array
Math
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size()-1;
        int not_nine = -1;

        if(digits[len] < 9)
        {
            digits[len]++;
            return digits;
        }
        
        for(int ind=0; ind<digits.size(); ind++)    if(digits[ind]!=9)      not_nine=ind;

        if(not_nine >= 0)
        {
            digits[not_nine]++;
            for(int ind=not_nine+1; ind<=len; ind++)    
                digits[ind] = 0;
        }
        else
        {
            vector<int> digits_copy(len+2, 0);
            digits_copy[0] = 1;
            return digits_copy;
        }

        return digits;
    }
};