/*
2325. Decode the Message
Easy
693
73
company
Coinbase

You are given the strings key and message, which represent a cipher key and a secret message, respectively. The steps to decode message are as follows:

    Use the first appearance of all 26 lowercase English letters in key as the order of the substitution table.
    Align the substitution table with the regular English alphabet.
    Each letter in message is then substituted using the table.
    Spaces ' ' are transformed to themselves.

    For example, given key = "happy boy" (actual key would have at least one instance of each letter in the alphabet), we have the partial substitution table of ('h' -> 'a', 'a' -> 'b', 'p' -> 'c', 'y' -> 'd', 'b' -> 'e', 'o' -> 'f').

Return the decoded message.

 

Example 1:

Input: key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv"
Output: "this is a secret"
Explanation: The diagram above shows the substitution table.
It is obtained by taking the first appearance of each letter in "the quick brown fox jumps over the lazy dog".

Example 2:

Input: key = "eljuxhpwnyrdgtqkviszcfmabo", message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb"
Output: "the five boxing wizards jump quickly"
Explanation: The diagram above shows the substitution table.
It is obtained by taking the first appearance of each letter in "eljuxhpwnyrdgtqkviszcfmabo".

 

Constraints:

    26 <= key.length <= 2000
    key consists of lowercase English letters and ' '.
    key contains every letter in the English alphabet ('a' to 'z') at least once.
    1 <= message.length <= 2000
    message consists of lowercase English letters and ' '.

Accepted
60.5K
Submissions
72K
Acceptance Rate
84.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (7)
Related Topics
Hash Table
String
*/
class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char, char> decode;
        string result = "";
        char ind = 'a';

        for(auto c : key)
            if(c>='a' && c<='z' && decode[c]==0)
                decode[c] = ind++;
                
        for(auto ch : message)
            if(ch>='a' && ch<='z')      
                result += decode[ch];
            else                        
                result += " ";

        return result;
    }
};