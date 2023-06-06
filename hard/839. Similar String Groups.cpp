/*
839. Similar String Groups
Hard
2.2K
212
company
Google
company
PayTM
company
DoorDash

Two strings, X and Y, are considered similar if either they are identical or we can make them equivalent by swapping at most two letters (in distinct positions) within the string X.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?

 

Example 1:

Input: strs = ["tars","rats","arts","star"]
Output: 2

Example 2:

Input: strs = ["omv","ovm"]
Output: 1

 

Constraints:

    1 <= strs.length <= 300
    1 <= strs[i].length <= 300
    strs[i] consists of lowercase letters only.
    All words in strs have the same length and are anagrams of each other.

Accepted
108.4K
Submissions
199.3K
Acceptance Rate
54.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (48)
Similar Questions
Groups of Strings
Hard
Related Topics
Array
String
Depth-First Search
Breadth-First Search
Union Find
*/

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visit) 
    {
        visit[node] = true;
        for (int neighbor : adj[node]) 
            if (!visit[neighbor]) 
                dfs(neighbor, adj, visit);
    }

    bool isSimilar(string& a, string& b) 
    {
        int diff = 0;

        for (int i = 0; i < a.size(); i++) 
            if (a[i] != b[i]) 
                diff++;
            
        return diff == 0 || diff == 2;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> adj(n);
        vector<bool> visit(n);
        int count = 0;

        for (int i = 0; i < n; i++) 
            for (int j = i + 1; j < n; j++) 
                if (isSimilar(strs[i], strs[j])) 
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }

        for (int i = 0; i < n; i++) 
            if (!visit[i]) 
            {
                dfs(i, adj, visit);
                count++;
            }

        return count;   
    }
};