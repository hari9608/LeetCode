/*

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:

Input: lists = []
Output: []

Example 3:

Input: lists = [[]]
Output: []

 

Constraints:

    k == lists.length
    0 <= k <= 104
    0 <= lists[i].length <= 500
    -104 <= lists[i][j] <= 104
    lists[i] is sorted in ascending order.
    The sum of lists[i].length will not exceed 104.

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
    typedef ListNode Node;
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        Node *merged_head = NULL;
        Node *tail = NULL;
        if(list1->val < list2->val)
        {
            merged_head = tail = list1;
            list1 = list1->next;
        }
        else
        {
            merged_head = tail = list2;
            list2 = list2->next;
        }
        while(list1 != NULL && list2 != NULL)
        {
            if(list1->val < list2->val)
            {

                tail->next = list1;
                tail = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                tail = list2;
                list2 = list2->next;
            }
        }
        if(list1 == NULL) tail->next = list2;
        if(list2 == NULL) tail->next = list1;

        return merged_head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        Node *merged_k_lists_head = NULL;

        for(auto list : lists)
            merged_k_lists_head = mergeTwoLists(merged_k_lists_head, list);

        return merged_k_lists_head;
    }
};