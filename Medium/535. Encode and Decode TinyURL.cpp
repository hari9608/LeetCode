/*
535. Encode and Decode TinyURL
Medium
1.8K
3.4K
company
Bloomberg
company
Microsoft
company
Amazon

    Note: This is a companion problem to the System Design problem: Design TinyURL.

TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk. Design a class to encode a URL and decode a tiny URL.

There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

Implement the Solution class:

    Solution() Initializes the object of the system.
    String encode(String longUrl) Returns a tiny URL for the given longUrl.
    String decode(String shortUrl) Returns the original long URL for the given shortUrl. It is guaranteed that the given shortUrl was encoded by the same object.

 

Example 1:

Input: url = "https://leetcode.com/problems/design-tinyurl"
Output: "https://leetcode.com/problems/design-tinyurl"

Explanation:
Solution obj = new Solution();
string tiny = obj.encode(url); // returns the encoded tiny url.
string ans = obj.decode(tiny); // returns the original url after decoding it.

 

Constraints:

    1 <= url.length <= 104
    url is guranteed to be a valid URL.

Accepted
225.7K
Submissions
262.6K
Acceptance Rate
85.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (8)
Related Topics
Hash Table
String
Design
Hash Function

*/
class Solution {
public:
    map<string, string> tiny_url;
    int n = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string encode = "https://leetcode.com/" + to_string(n);
        tiny_url[encode] = longUrl;
        n++;
        return encode;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return tiny_url[shortUrl];
    }
};
// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));