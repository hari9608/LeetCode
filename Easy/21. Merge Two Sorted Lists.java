/*
21. Merge Two Sorted Lists
Easy
18.5K
1.7K
company
Amazon
company
Apple
company
Expedia

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:

Input: list1 = [], list2 = []
Output: []

Example 3:

Input: list1 = [], list2 = [0]
Output: [0]

 

Constraints:

    The number of nodes in both lists is in the range [0, 50].
    -100 <= Node.val <= 100
    Both list1 and list2 are sorted in non-decreasing order.

Accepted
3.3M
Submissions
5.2M
Acceptance Rate
62.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (157)
Similar Questions
Merge k Sorted Lists
Hard
Merge Sorted Array
Easy
Sort List
Medium
Shortest Word Distance II
Medium
Add Two Polynomials Represented as Linked Lists
Medium
Longest Common Subsequence Between Sorted Arrays
Medium
Merge Two 2D Arrays by Summing Values
Easy
Related Topics
Linked List
Recursion
*/
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode merged_list = new ListNode(-1);
        ListNode prev = merged_list;

        while(list1 != null && list2 != null)
        {
            if(list1.val <= list2.val)
            {
                prev.next = list1;
                list1 = list1.next;
            }
            else
            {
                prev.next = list2;
                list2 = list2.next;
            }
            prev = prev.next;
        }

        prev.next = list1 == null ? list2 : list1;

        return merged_list.next;
    }
}