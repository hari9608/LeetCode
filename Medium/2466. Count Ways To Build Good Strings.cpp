/*
2466. Count Ways To Build Good Strings
Medium
1.5K
130
Oracle

Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:

    Append the character '0' zero times.
    Append the character '1' one times.

This can be performed any number of times.

A good string is a string constructed by the above process having a length between low and high (inclusive).

Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.

 

Example 1:

Input: low = 3, high = 3, zero = 1, one = 1
Output: 8
Explanation: 
One possible valid good string is "011". 
It can be constructed as follows: "" -> "0" -> "01" -> "011". 
All binary strings from "000" to "111" are good strings in this example.

Example 2:

Input: low = 2, high = 3, zero = 1, one = 2
Output: 5
Explanation: The good strings are "00", "11", "000", "110", and "011".

 

Constraints:

    1 <= low <= high <= 105
    1 <= zero, one <= low

Accepted
59.2K
Submissions
104K
Acceptance Rate
56.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (56)
Similar Questions
Climbing Stairs
Easy
Related Topics
Dynamic Programming
*/
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long> good_strings(high + 1);
        int count_good_strings = 0;
        good_strings[0] = 1;
        long mod = 1000000007;

        for(int pos = 1; pos <= high; pos++)
        {
            if(pos >= zero)
                good_strings[pos] += good_strings[pos - zero];

            if(pos >= one)
                good_strings[pos] += good_strings[pos - one];

            good_strings[pos] %= mod;
        }

        for(int i = low; i <= high; i++)
        {
            count_good_strings = count_good_strings + good_strings[i];
            count_good_strings %= mod;
        }

        return count_good_strings;
    }
};