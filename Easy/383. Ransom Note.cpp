/*
383. Ransom Note
Easy
4K
423
company
Adobe
company
Amazon
company
Spotify

Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true

 

Constraints:

    1 <= ransomNote.length, magazine.length <= 105
    ransomNote and magazine consist of lowercase English letters.

Accepted
778K
Submissions
1.3M
Acceptance Rate
58.6%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (33)
Similar Questions
Stickers to Spell Word
Hard
Related Topics
Hash Table
String
Counting
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> umap;

        for(int index=0; index<magazine.size(); index++)
            if(umap.count(magazine[index])) 
                umap[magazine[index]]++;
            else 
                umap[magazine[index]] = 1;
            
        for(int index=0; index<ransomNote.size(); index++)
            if(umap[ransomNote[index]] >= 1) 
                --umap[ransomNote[index]];
            else 
                return false;
        
        return true;
    }
};