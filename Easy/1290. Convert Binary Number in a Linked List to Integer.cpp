/*
1290. Convert Binary Number in a Linked List to Integer
Easy
3.7K
147
JPMorgan
Oracle
company
Amazon

Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.

 

Example 1:

Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10

Example 2:

Input: head = [0]
Output: 0

 

Constraints:

    The Linked List is not empty.
    Number of nodes will not exceed 30.
    Each node's value is either 0 or 1.

Accepted
388.4K
Submissions
474.2K
Acceptance Rate
81.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (12)
Related Topics
Linked List
Math
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int decimal = 0;
        if(head->val == 1) decimal=1;
        head = head->next;
        while(head!=NULL){
            decimal = decimal*2;
            if(head->val == 1) decimal+=1;
            head = head->next;
        }

        return decimal;
    }
};