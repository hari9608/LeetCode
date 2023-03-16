/*
692. Top K Frequent Words
Medium
6.8K
317
company
Amazon
company
Uber
company
Bloomberg

Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

 

Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.

 

Constraints:

    1 <= words.length <= 500
    1 <= words[i].length <= 10
    words[i] consists of lowercase English letters.
    k is in the range [1, The number of unique words[i]]

 

Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
Accepted
532.7K
Submissions
932.5K
Acceptance Rate
57.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (14)
Similar Questions
Top K Frequent Elements
Medium
K Closest Points to Origin
Medium
Sort Features by Popularity
Medium
Sender With Largest Word Count
Medium
Maximum Number of Pairs in Array
Easy
Related Topics
Hash Table
String
Trie
Sorting
Heap (Priority Queue)
Bucket Sort
Counting

*/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<int, string>> kfre;
        map<string, int> nums_fre;
        vector<string> result;
        int ind = 0;
        
        for(string v:words)             nums_fre[v]++;
        for(auto num: nums_fre)         kfre.push_back({num.second, num.first});

        auto comp = [](pair<int, string>& p1, pair<int, string>& p2) 
        {
            if(p1.first == p2.first)    return p1.second < p2.second;
            
            return p1.first > p2.first;
        };

        sort(begin(kfre), end(kfre), comp);

        while(k != ind)                 result.push_back(kfre[ind++].second);

        return result;
    }
};