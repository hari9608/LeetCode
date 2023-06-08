/*
83. Remove Duplicates from Sorted List
Easy
7.4K
250
company
Amazon
company
Adobe
company
Google

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

Example 1:

Input: head = [1,1,2]
Output: [1,2]

Example 2:

Input: head = [1,1,2,3,3]
Output: [1,2,3]

 

Constraints:

    The number of nodes in the list is in the range [0, 300].
    -100 <= Node.val <= 100
    The list is guaranteed to be sorted in ascending order.

Accepted
1.2M
Submissions
2.4M
Acceptance Rate
50.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (41)
Similar Questions
Remove Duplicates from Sorted List II
Medium
Remove Duplicates From an Unsorted Linked List
Medium
Related Topics
Linked List
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;

        while (current && current->next)
            if (current->next->val == current->val)
                current->next = current->next->next;
            else
                current = current->next;
            
        return head;
    }
};