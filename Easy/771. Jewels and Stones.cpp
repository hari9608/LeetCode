/*
771. Jewels and Stones
Easy
4.6K
550
company
Adobe
company
Amazon
company
Apple

You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".

 

Example 1:

Input: jewels = "aA", stones = "aAAbbbb"
Output: 3

Example 2:

Input: jewels = "z", stones = "ZZ"
Output: 0

 

Constraints:

    1 <= jewels.length, stones.length <= 50
    jewels and stones consist of only English letters.
    All the characters of jewels are unique.

Accepted
884.4K
Submissions
1M
Acceptance Rate
88.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (24)
Related Topics
Hash Table
String
*/
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {

        map<char, int> stone;
        int res = 0;
        
        for(char st : stones)       stone[st]++;
        for(char jw : jewels)       res+=stone[jw];
        return res;
    }
};