/*
243. Shortest Word Distance
Easy
1.2K
107
company
LinkedIn
company
Amazon
company
Microsoft

Given an array of strings wordsDict and two different strings that already exist in the array word1 and word2, return the shortest distance between these two words in the list.

 

Example 1:

Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "coding", word2 = "practice"
Output: 3

Example 2:

Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "coding"
Output: 1

 

Constraints:

    2 <= wordsDict.length <= 3 * 104
    1 <= wordsDict[i].length <= 10
    wordsDict[i] consists of lowercase English letters.
    word1 and word2 are in wordsDict.
    word1 != word2

Accepted
202K
Submissions
310.5K
Acceptance Rate
65.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (1)
Similar Questions
Shortest Word Distance II
Medium
Shortest Word Distance III
Medium
Find All K-Distant Indices in an Array
Easy
Related Topics
Array
String
*/
class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int w1_ind = -1;
        int w2_ind = -1;
        int shortest_distance = wordsDict.size();

        for(int i=0; i<wordsDict.size(); i++)
        {
            if(wordsDict[i] == word1)
                w1_ind = i;
            if(wordsDict[i] == word2)     
                w2_ind = i;
            if(w1_ind != -1 && w2_ind != -1)
                shortest_distance = min(shortest_distance, abs(w1_ind - w2_ind));
        }

        return shortest_distance;
    }
};