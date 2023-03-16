/*
1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
Medium
2.1K
1.3K
company
Amazon
company
Adobe
company
Bloomberg

A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.

Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.

 

Example 1:

Input: n = "32"
Output: 3
Explanation: 10 + 11 + 11 = 32

Example 2:

Input: n = "82734"
Output: 8

Example 3:

Input: n = "27346209830709182346"
Output: 9

 

Constraints:

    1 <= n.length <= 105
    n consists of only digits.
    n does not contain any leading zeros and represents a positive integer.

Accepted
169.2K
Submissions
189.6K
Acceptance Rate
89.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (17)
Related Topics
String
Greedy

*/
class Solution {
public:
    int minPartitions(string n) {
        int minimum_deci_binary;
        for(char c : n) minimum_deci_binary = max(minimum_deci_binary, c-'0');
        return minimum_deci_binary;
    }
};