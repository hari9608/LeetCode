/*
605. Can Place Flowers
Easy
5.1K
852
company
LinkedIn
company
Facebook
company
Amazon

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

 

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false

 

Constraints:

    1 <= flowerbed.length <= 2 * 104
    flowerbed[i] is 0 or 1.
    There are no two adjacent flowers in flowerbed.
    0 <= n <= flowerbed.length

Accepted
448.9K
Submissions
1.4M
Acceptance Rate
32.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (62)
Similar Questions
Teemo Attacking
Easy
Asteroid Collision
Medium
Related Topics
Array
Greedy
*/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int can_place_flowers = 0;

        for(int flower = 0; flower < flowerbed.size(); flower++)
        {
            if(!flowerbed[flower])
            {
                bool empty_left_plot = (!flower) || (!flowerbed[flower - 1]);                       // SET TRUE IF 0 OR BEFORE INDEX IS ZERO
                bool empty_right_plot = (flower == flowerbed.size()-1) || (!flowerbed[flower + 1]); // SET TRUE IF LAST OR NEXT INDEX IS TRUE
                if(empty_left_plot && empty_right_plot)                                             // INCREMENT THE PLANT FLOWER COUNT
                {
                    flowerbed[flower] = 1;
                    can_place_flowers++;
                }
            }
        }

        return can_place_flowers >= n;
    }
};