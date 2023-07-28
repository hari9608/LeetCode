/*
1125. Smallest Sufficient Team
Hard
2K
52
company
Amazon

In a project, you have a list of required skills req_skills, and a list of people. The ith person people[i] contains a list of skills that the person has.

Consider a sufficient team: a set of people such that for every required skill in req_skills, there is at least one person in the team who has that skill. We can represent these teams by the index of each person.

    For example, team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].

Return any sufficient team of the smallest possible size, represented by the index of each person. You may return the answer in any order.

It is guaranteed an answer exists.

 

Example 1:

Input: req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
Output: [0,2]

Example 2:

Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
Output: [1,2]

 

Constraints:

    1 <= req_skills.length <= 16
    1 <= req_skills[i].length <= 16
    req_skills[i] consists of lowercase English letters.
    All the strings of req_skills are unique.
    1 <= people.length <= 60
    0 <= people[i].length <= 16
    1 <= people[i][j].length <= 16
    people[i][j] consists of lowercase English letters.
    All the strings of people[i] are unique.
    Every skill in people[i] is a skill in req_skills.
    It is guaranteed a sufficient team exists.

Accepted
56.6K
Submissions
99.6K
Acceptance Rate
56.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (39)
Similar Questions
The Number of Good Subsets
Hard
Minimum Number of Work Sessions to Finish the Tasks
Medium
Maximum Rows Covered by Columns
Medium
Related Topics
Array
Dynamic Programming
Bit Manipulation
Bitmask
*/
class Solution {
public:
   vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> skills;
        int n_req = req_skills.size();
        int m_people = people.size();
        vector<int> people_skill(m_people);
        int s = 1 << n_req; 
        vector<int> dp(s, INT_MAX);
        vector<int> parent(s, -1);
        vector<int> parent_state(s);
        dp[0] = 0;
        int temp = (1 << n_req) - 1;
        vector<int> smallest_sufficient_team;

        for (int i = 0; i < req_skills.size(); ++i)
            skills[req_skills[i]] = i;

        for (int i = 0; i < m_people; ++i)
            for (int j = 0; j < people[i].size(); ++j)
            {
                int temp = skills[people[i][j]];
                people_skill[i] |= (1 << temp);
            }

        for (int i = 0; i < (1 << n_req); ++i)
            for (int j = 0; j < m_people; ++j)
            {
                if (dp[i] == INT_MAX) 
                    continue;
                    
                int temp = i | people_skill[j];

                if (dp[temp] > dp[i]+1) 
                {
                    parent[temp] = j; 
                    parent_state[temp] = i; 
                    dp[temp] = dp[i] + 1;
                }         
            }
               
        while (parent[temp] != -1)
        {
            smallest_sufficient_team.push_back(parent[temp]);
            temp = parent_state[temp];
        }
        
        return smallest_sufficient_team;
    }
};