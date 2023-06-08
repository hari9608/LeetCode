/*
1065. Index Pairs of a String
Easy
352
103
company
Amazon

Given a string text and an array of strings words, return an array of all index pairs [i, j] so that the substring text[i...j] is in words.

Return the pairs [i, j] in sorted order (i.e., sort them by their first coordinate, and in case of ties sort them by their second coordinate).

 

Example 1:

Input: text = "thestoryofleetcodeandme", words = ["story","fleet","leetcode"]
Output: [[3,7],[9,13],[10,17]]

Example 2:

Input: text = "ababa", words = ["aba","ab"]
Output: [[0,1],[0,2],[2,3],[2,4]]
Explanation: Notice that matches can overlap, see "aba" is found in [0,2] and [2,4].

 

Constraints:

    1 <= text.length <= 100
    1 <= words.length <= 20
    1 <= words[i].length <= 50
    text and words[i] consist of lowercase English letters.
    All the strings of words are unique.

Accepted
25.4K
Submissions
38.2K
Acceptance Rate
66.6%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (3)
Related Topics
*/
class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        int text_len = text.size();
        vector<vector<int>> index_pairs;
        set<string> words_set(words.begin(), words.end());

        for(int st = 0; st < text_len; st++)
            for(int en = st; en < text_len; en++)
                if(words_set.count(text.substr(st, en - st + 1)))
                    index_pairs.push_back({st, en});

        return index_pairs;
    }
};