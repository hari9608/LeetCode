/*
1323. Maximum 69 Number
Easy
2.5K
203
company
Adobe
HRT

You are given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

 

Example 1:

Input: num = 9669
Output: 9969
Explanation: 
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666.
The maximum number is 9969.

Example 2:

Input: num = 9996
Output: 9999
Explanation: Changing the last digit 6 to 9 results in the maximum number.

Example 3:

Input: num = 9999
Output: 9999
Explanation: It is better not to apply any change.

 

Constraints:

    1 <= num <= 104
    num consists of only 6 and 9 digits.

Accepted
219.6K
Submissions
267.7K
Acceptance Rate
82.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (58)
Related Topics
Math
Greedy
*/
class Solution {
public:
    int maximum69Number (int num) {
        int dup_num = num;
        int to_add = -1;
        int curr = 0;
        while(dup_num > 0)
        {
            if(dup_num % 10 == 6)
                to_add = curr;
            dup_num /= 10;
            curr++;
        }
        return to_add == -1 ? num : num + 3 * (int)pow(10, to_add);
    }
};