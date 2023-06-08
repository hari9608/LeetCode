/*
1086. High Five
Easy
756
120
company
Goldman Sachs
company
Amazon

Given a list of the scores of different students, items, where items[i] = [IDi, scorei] represents one score from a student with IDi, calculate each student's top five average.

Return the answer as an array of pairs result, where result[j] = [IDj, topFiveAveragej] represents the student with IDj and their top five average. Sort result by IDj in increasing order.

A student's top five average is calculated by taking the sum of their top five scores and dividing it by 5 using integer division.

 

Example 1:

Input: items = [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
Output: [[1,87],[2,88]]
Explanation: 
The student with ID = 1 got scores 91, 92, 60, 65, 87, and 100. Their top five average is (100 + 92 + 91 + 87 + 65) / 5 = 87.
The student with ID = 2 got scores 93, 97, 77, 100, and 76. Their top five average is (100 + 97 + 93 + 77 + 76) / 5 = 88.6, but with integer division their average converts to 88.

Example 2:

Input: items = [[1,100],[7,100],[1,100],[7,100],[1,100],[7,100],[1,100],[7,100],[1,100],[7,100]]
Output: [[1,100],[7,100]]

 

Constraints:

    1 <= items.length <= 1000
    items[i].length == 2
    1 <= IDi <= 1000
    0 <= scorei <= 100
    For each IDi, there will be at least five scores.

Accepted
94.2K
Submissions
125.7K
Acceptance Rate
75.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (1)
Similar Questions
Determine the Winner of a Bowling Game
Easy
Related Topics
Array
Hash Table
Sorting
*/
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int>> student_id_score;
        vector<vector<int>> high_five;

        for(auto item : items)      student_id_score[item[0]].push(item[1]);

        for(auto id_score : student_id_score)
        {
            int k = 5;
            int five_sum = 0;
            vector<int> each;

            each.push_back(id_score.first);

            while(k--)
            {
                five_sum += id_score.second.top();
                id_score.second.pop();
            }

            each.push_back((int)(floor)(five_sum / 5));

            high_five.push_back(each);
        }

        return high_five; 
    }
};