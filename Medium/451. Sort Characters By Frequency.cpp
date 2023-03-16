/*
451. Sort Characters By Frequency
Medium
6.4K
227
company
Bloomberg
company
Microsoft
company
Amazon

Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

 

Constraints:

    1 <= s.length <= 5 * 105
    s consists of uppercase and lowercase English letters and digits.

Accepted
494.4K
Submissions
705.8K
Acceptance Rate
70.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (20)
Similar Questions
Top K Frequent Elements
Medium
First Unique Character in a String
Easy
Sort Array by Increasing Frequency
Easy
Percentage of Letter in String
Easy
Maximum Number of Pairs in Array
Easy
Node With Highest Edge Score
Medium
Most Frequent Even Element
Easy
Count Pairs Of Similar Strings
Easy
Related Topics
Hash Table
String
Sorting
Heap (Priority Queue)
Bucket Sort
Counting

*/
class Solution {
public:
    string frequencySort(string s) {
        map<char, int> cmap;
        for(char c:s)   cmap[c]++;
        
        map<int, string> smap;
        for(auto cm: cmap)
        {
            int n = cm.second;
            while(n--)
            smap[-cm.second] += cm.first;
        }

        string str = "";
        for(auto sm: smap)      str += sm.second;
        
        return str;
    }
};
/*

t -> 1
r -> 1
e -> 2

1 -> tr
2 -> e

*/


