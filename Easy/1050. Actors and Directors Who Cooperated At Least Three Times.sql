/*
1050. Actors and Directors Who Cooperated At Least Three Times
Easy
498
41
company
Amazon
SQL Schema

Table: ActorDirector

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| actor_id    | int     |
| director_id | int     |
| timestamp   | int     |
+-------------+---------+
timestamp is the primary key column for this table.

 

Write a SQL query for a report that provides the pairs (actor_id, director_id) where the actor has cooperated with the director at least three times.

Return the result table in any order.

The query result format is in the following example.

 

Example 1:

Input: 
ActorDirector table:
+-------------+-------------+-------------+
| actor_id    | director_id | timestamp   |
+-------------+-------------+-------------+
| 1           | 1           | 0           |
| 1           | 1           | 1           |
| 1           | 1           | 2           |
| 1           | 2           | 3           |
| 1           | 2           | 4           |
| 2           | 1           | 5           |
| 2           | 1           | 6           |
+-------------+-------------+-------------+
Output: 
+-------------+-------------+
| actor_id    | director_id |
+-------------+-------------+
| 1           | 1           |
+-------------+-------------+
Explanation: The only pair is (1, 1) where they cooperated exactly 3 times.

Accepted
120.9K
Submissions
172.7K
Acceptance Rate
70.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (21)
Related Topics
Database
*/
# Write your MySQL query statement below
select actor_id,director_id
from ActorDirector 
group by actor_id,director_id
Having count(timestamp)>=3;






