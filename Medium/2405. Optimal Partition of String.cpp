/*
2405. Optimal Partition of String
Medium
2.1K
80
company
Microsoft
company
Amazon

Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.

 

Example 1:

Input: s = "abacaba"
Output: 4
Explanation:
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.

Example 2:

Input: s = "ssssss"
Output: 6
Explanation:
The only valid partition is ("s","s","s","s","s","s").

 

Constraints:

    1 <= s.length <= 105
    s consists of only English lowercase letters.

Accepted
116.9K
Submissions
146.4K
Acceptance Rate
79.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (47)
Similar Questions
Longest Substring Without Repeating Characters
Medium
Longest Substring with At Least K Repeating Characters
Medium
Partition Labels
Medium
Partition Array into Disjoint Intervals
Medium
Maximum Sum of Distinct Subarrays With Length K
Medium
Related Topics
Hash Table
String
Greedy

*/
class Solution {
public:
    int partitionString(string s) {
        vector<int> status(26, -1);
        int no_of_partition = 1;
        int current_status = 0;

        for(int i = 0; i < s.length(); i++)
        {
            if(status[s[i] - 'a'] >= current_status)
            {
                no_of_partition++;
                current_status = i;
            }
            status[s[i] - 'a'] = i;
        }

        return no_of_partition;
    }
};