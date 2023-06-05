/*
208. Implement Trie (Prefix Tree)
Medium
10K
116
company
Amazon
company
Google
company
Twitter

A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

    Trie() Initializes the trie object.
    void insert(String word) Inserts the string word into the trie.
    boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
    boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True

 

Constraints:

    1 <= word.length, prefix.length <= 2000
    word and prefix consist only of lowercase English letters.
    At most 3 * 104 calls in total will be made to insert, search, and startsWith.

Accepted
805.4K
Submissions
1.3M
Acceptance Rate
62.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (26)
Similar Questions
Design Add and Search Words Data Structure
Medium
Design Search Autocomplete System
Hard
Replace Words
Medium
Implement Magic Dictionary
Medium
Encrypt and Decrypt Strings
Hard
Implement Trie II (Prefix Tree)
Medium
Related Topics
Hash Table
String
Design
Trie
*/

class Trie {

    map<string, int> trie;
    map<string, int> prefix_words;

public:
    Trie() {
        
    }
    
    void insert(string word) {
        trie[word]++;

        for(int i=0; i<=word.size(); i++)    prefix_words[word.substr(0,i)]++;

    }
    
    bool search(string word) {
        return trie[word] ;
    }
    
    bool startsWith(string prefix) {
        return prefix_words[prefix];
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */