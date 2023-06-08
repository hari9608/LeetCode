/*
206. Reverse Linked List
Easy
18.1K
336
company
Apple
company
Amazon
company
Bloomberg

Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:

Input: head = [1,2]
Output: [2,1]

Example 3:

Input: head = []
Output: []

 

Constraints:

    The number of nodes in the list is the range [0, 5000].
    -5000 <= Node.val <= 5000

 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
Accepted
3.1M
Submissions
4.2M
Acceptance Rate
73.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (71)
Similar Questions
Reverse Linked List II
Medium
Binary Tree Upside Down
Medium
Palindrome Linked List
Easy
Reverse Nodes in Even Length Groups
Medium
Maximum Twin Sum of a Linked List
Medium
Remove Nodes From Linked List
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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = NULL, *ne = NULL;
        while(head != NULL){
            ne = head->next;
            head->next = temp;
            temp = head;
            head = ne;
        }
        return temp;
    }
};