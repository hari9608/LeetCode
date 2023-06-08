/*
203. Remove Linked List Elements
Easy
7.3K
209
company
Amazon
company
Apple
company
Google

Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

Example 1:

Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:

Input: head = [], val = 1
Output: []

Example 3:

Input: head = [7,7,7,7], val = 7
Output: []

 

Constraints:

    The number of nodes in the list is in the range [0, 104].
    1 <= Node.val <= 50
    0 <= val <= 50

Accepted
939.9K
Submissions
2M
Acceptance Rate
46.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (23)
Similar Questions
Remove Element
Easy
Delete Node in a Linked List
Medium
Delete the Middle Node of a Linked List
Medium
Related Topics
Linked List
Recursion
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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val) head = head->next;
        ListNode* temp = head;

        while(temp)
        {
            if(temp->next && temp->next->val == val)  temp->next = temp->next->next;
            else temp = temp->next;
        }

        return head;
    }
};