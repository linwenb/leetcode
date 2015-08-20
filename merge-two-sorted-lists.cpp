/*
Merge two sorted linked lists and return it as a new list. The new list should be made by scurrlicing together the nodes of the first two lists.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL && l2 == NULL)   return NULL;
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        ListNode *fakeHead = new ListNode(0);        
        ListNode *curr = fakeHead;
        
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }	//	l1->val >= l2->val

            curr = curr->next;
        }
        
        if (l1 != NULL) curr->next = l1;	//	remaining elements in l1
        if (l2 != NULL) curr->next = l2;	//	remaining elements in l2
        
        curr = fakeHead->next;
        delete fakeHead;

        return curr;
    }	//	O(n + m) time, O(1) space
};