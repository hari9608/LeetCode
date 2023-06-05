/*
211. Design Add and Search Words Data Structure
Medium
6.8K
384
company
Google
company
Amazon
company
Apple

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

    WordDictionary() Initializes the object.
    void addWord(word) Adds word to the data structure, it can be matched later.
    bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.

 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True

 

Constraints:

    1 <= word.length <= 25
    word in addWord consists of lowercase English letters.
    word in search consist of '.' or lowercase English letters.
    There will be at most 2 dots in word for search queries.
    At most 104 calls will be made to addWord and search.

Accepted
520.8K
Submissions
1.2M
Acceptance Rate
44.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (50)
Similar Questions
Implement Trie (Prefix Tree)
Medium
Prefix and Suffix Search
Hard
Match Substring After Replacement
Hard
Sum of Prefix Scores of Strings
Hard
Related Topics
String
Depth-First Search
Design
Trie
*/

class TrieNode  {
public:
    unordered_map<char, TrieNode*> child;
    bool isWord;
    
    TrieNode() 
    {
        isWord = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        
        for (auto c : word) 
        {
            if (node->child.find(c) == node->child.end()) 
                node->child[c] = new TrieNode();
            node = node->child[c];
        }

        node->isWord = true;
    }
    
    bool search(string word) {
        return searchHelper(root, word, 0);
    }

    bool searchHelper(TrieNode* node, string& word, int index) {
        if (index == word.length())         return node->isWord;

        char c = word[index];
        
        if (c == '.') 
        {
            for (auto& p : node->child)
                if (searchHelper(p.second, word, index + 1))
                    return true;
                
            return false;
        } 
        else 
        {
            if (node->child.find(c) == node->child.end())       return false;
            TrieNode* child = node->child[c];
            return searchHelper(child, word, index + 1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */