/*
2140. Solving Questions With Brainpower
Medium
2.1K
51
company
Amazon

You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].

The array describes the questions of an exam, where you have to process the questions in order (i.e., starting from question 0) and make a decision whether to solve or skip each question. Solving question i will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions. If you skip question i, you get to make the decision on the next question.

    For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
        If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
        If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be unable to solve questions 2 and 3.

Return the maximum points you can earn for the exam.

 

Example 1:

Input: questions = [[3,2],[4,3],[4,4],[2,5]]
Output: 5
Explanation: The maximum points can be earned by solving questions 0 and 3.
- Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
- Unable to solve questions 1 and 2
- Solve question 3: Earn 2 points
Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.

Example 2:

Input: questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
Output: 7
Explanation: The maximum points can be earned by solving questions 1 and 4.
- Skip question 0
- Solve question 1: Earn 2 points, will be unable to solve the next 2 questions
- Unable to solve questions 2 and 3
- Solve question 4: Earn 5 points
Total points earned: 2 + 5 = 7. There is no other way to earn 7 or more points.

 

Constraints:

    1 <= questions.length <= 105
    questions[i].length == 2
    1 <= pointsi, brainpoweri <= 105

Accepted
81.3K
Submissions
146.5K
Acceptance Rate
55.5%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (63)
Similar Questions
House Robber
Medium
Frog Jump
Hard
Related Topics
Array
Dynamic Programming
*/
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int questions_len = questions.size();
        vector<long long> most_points(questions_len);
        most_points[questions_len - 1] = questions[questions_len - 1][0];
        
        for (int i = questions_len - 2; i >= 0; --i) 
        {
            most_points[i] = questions[i][0];
            int skip = questions[i][1];

            if (i + skip + 1 < questions_len) 
                most_points[i] += most_points[i + skip + 1];
            
            most_points[i] = max(most_points[i], most_points[i + 1]);
        }

        return most_points[0];
    }
};