/*
49. Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:

Input: strs = [""]
Output: [[""]]

Example 3:

Input: strs = ["a"]
Output: [["a"]]

 

Constraints:

    1 <= strs.length <= 104
    0 <= strs[i].length <= 100
    strs[i] consists of lowercase English letters.

*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> group_anagrams;
        map<string, vector<string>> smap;
        for(auto str:strs){
            string temp = str;
            sort(str.begin(), str.end());
            smap[str].push_back(temp);
        }

        for(auto sm:smap){
            vector<string> anagram;
            for(auto s:sm.second)
                anagram.push_back(s);
            group_anagrams.push_back(anagram);
        }
        return group_anagrams;
    }
};