/*
997. Find the Town Judge
Easy
5.6K
449
company
Apple
company
Amazon
company
Google

In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

    The town judge trusts nobody.
    Everybody (except for the town judge) trusts the town judge.
    There is exactly one person that satisfies properties 1 and 2.

You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

 

Example 1:

Input: n = 2, trust = [[1,2]]
Output: 2

Example 2:

Input: n = 3, trust = [[1,3],[2,3]]
Output: 3

Example 3:

Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1

 

Constraints:

    1 <= n <= 1000
    0 <= trust.length <= 104
    trust[i].length == 2
    All the pairs of trust are unique.
    ai != bi
    1 <= ai, bi <= n

Accepted
412.8K
Submissions
834.5K
Acceptance Rate
49.5%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (88)
Similar Questions
Find the Celebrity
Medium
Related Topics
Array
Hash Table
Graph
*/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int no_of_trust = trust.size();
        if(!no_of_trust && n==1)    return 1;
        if(no_of_trust < n-1)    return -1;

        map<int, int> trust_for_judge;
        map<int, int> trust_people;
        int judge = -1;

        for(auto pair : trust)      trust_for_judge[pair[1]]++,     trust_people[pair[0]]++;    
        
        for(auto find_judge : trust_for_judge)
            if(find_judge.second == n-1 && trust_people[find_judge.first] == 0)    
                judge = find_judge.first;

        return judge;
    }
};
/*
    n=4, trust = [[1,3],[2,3],[1,4],[2,4],[4,3],[3,4]] 
    trust of 3 are 1,2,4
    trust of 4 are 1,2,3

    no of trust for 3 is count 3;
    3 trust 4 so it is not valid;

    n=4, trust = [[1,3],[2,3],[1,4],[2,4],[4,3]] 
    trust of 3 are 1,2,4
    trust of 4 are 1,2

    no of trust for 3 is count 3;
    3 trust no one; so 3 is the judge;
*/