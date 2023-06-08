/*
989. Add to Array-Form of Integer
Easy
3.1K
252
company
Facebook
company
Bloomberg

The array-form of an integer num is an array representing its digits in left to right order.

    For example, for num = 1321, the array form is [1,3,2,1].

Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.

 

Example 1:

Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234

Example 2:

Input: num = [2,7,4], k = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455

Example 3:

Input: num = [2,1,5], k = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021

 

Constraints:

    1 <= num.length <= 104
    0 <= num[i] <= 9
    num does not contain any leading zeros except for the zero itself.
    1 <= k <= 104

Accepted
227.9K
Submissions
486.9K
Acceptance Rate
46.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (113)
Similar Questions
Add Two Numbers
Medium
Plus One
Easy
Add Binary
Easy
Add Strings
Easy
Related Topics
Array
Math
*/
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> add_to_array_form;
        int ind = num.size() - 1;
        int carry = 0;
        int add = 0;

        while(ind >= 0 || k > 0)
        {
            if(ind >= 0)    add = k % 10 + num[ind] + carry;
            else            add = k % 10 + carry;
            
            add_to_array_form.insert(add_to_array_form.begin(), add % 10);

            carry = add / 10;
            k = k / 10;
            ind--;
        }

        if(carry > 0)   add_to_array_form.insert(add_to_array_form.begin(), carry);
        
        return add_to_array_form;
    }
};