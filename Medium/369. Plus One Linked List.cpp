/*
369. Plus One Linked List
Medium
871
42
company
Google

Given a non-negative integer represented as a linked list of digits, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list.

 

Example 1:

Input: head = [1,2,3]
Output: [1,2,4]

Example 2:

Input: head = [0]
Output: [1]

 

Constraints:

    The number of nodes in the linked list is in the range [1, 100].
    0 <= Node.val <= 9
    The number represented by the linked list does not contain leading zeros except for the zero itself. 

Accepted
74.4K
Submissions
122K
Acceptance Rate
61.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (0)
Similar Questions
Plus One
Easy
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
    ListNode* plusOne(ListNode* head) {
        ListNode* new_empty_head = new ListNode(0);
        new_empty_head->next = head;
        ListNode* not_nine = new_empty_head;

        while(head)
        {
            if(head->val != 9)  not_nine = head;
            head = head->next;
        }

        not_nine->val++;
        not_nine = not_nine->next;

        while(not_nine)
        {
            not_nine->val = 0;
            not_nine = not_nine->next;
        }

        return new_empty_head->val ? new_empty_head : new_empty_head->next;
    }
};