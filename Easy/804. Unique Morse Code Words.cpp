/*
804. Unique Morse Code Words
Easy
2.3K
1.5K
company
Google
company
Amazon
company
Square

International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows:

    'a' maps to ".-",
    'b' maps to "-...",
    'c' maps to "-.-.", and so on.

For convenience, the full table for the 26 letters of the English alphabet is given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]

Given an array of strings words where each word can be written as a concatenation of the Morse code of each letter.

    For example, "cab" can be written as "-.-..--...", which is the concatenation of "-.-.", ".-", and "-...". We will call such a concatenation the transformation of a word.

Return the number of different transformations among all words we have.

 

Example 1:

Input: words = ["gin","zen","gig","msg"]
Output: 2
Explanation: The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."
There are 2 different transformations: "--...-." and "--...--.".

Example 2:

Input: words = ["a"]
Output: 1

 

Constraints:

    1 <= words.length <= 100
    1 <= words[i].length <= 12
    words[i] consists of lowercase English letters.

Accepted
317.8K
Submissions
384.6K
Acceptance Rate
82.6%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (15)
Related Topics
Array
Hash Table
String
*/
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> unique = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> uniques;
        for(auto word: words)
        {
            string represen = "";
            for(char c:word)
                represen += unique[c-'a'];
            uniques.insert(represen);
        }
        return uniques.size();
    }
};