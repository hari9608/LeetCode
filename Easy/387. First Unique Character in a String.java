/*
387. First Unique Character in a String
Easy
7.8K
255
company
Bloomberg
company
Amazon
company
Goldman Sachs

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0

Example 2:

Input: s = "loveleetcode"
Output: 2

Example 3:

Input: s = "aabb"
Output: -1

 

Constraints:

    1 <= s.length <= 105
    s consists of only lowercase English letters.

Accepted
1.4M
Submissions
2.4M
Acceptance Rate
59.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (29)
Similar Questions
Sort Characters By Frequency
Medium
First Letter to Appear Twice
Easy
Related Topics
Hash Table
String
Queue
Counting

*/
class Solution {
    public int firstUniqChar(String s) {

        for(int i=0; i<s.length(); i++)
            if(!s.substring(i+1).contains(s.substring(i,i+1)) && !s.substring(0,i).contains(s.substring(i,i+1)))
                return i;
        
        return -1;
    }
}