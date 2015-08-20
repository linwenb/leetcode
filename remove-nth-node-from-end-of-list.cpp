/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass.
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL)   return NULL;
        
        ListNode *fast = head;
        while (n-- > 0)	fast = fast->next;	//	help to find the last n-th node
        
        if (fast == NULL) {
            fast = head;
            head = head->next;
        }   //  the last n-th node is head
        else {
            ListNode *prev = head;	//	prev will point to the last (n+1)-th node
            while (fast->next != NULL) {
                prev = prev->next;
                fast = fast->next;
            }
            
            fast = prev->next;		//	fast points to the last n-th node
            prev->next = fast->next;	//	remove the last n-th node
        }

        delete fast;        
        return head;
    }	//	O(length) time, O(1) space
};