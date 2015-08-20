/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;	//	less than 2 nodes
        
        ListNode *pre = head;	//	the 1st node
        head = head->next;		//	the 2nd node

        ListNode *curr = head->next;	//	the 3rd node
        
        head->next = pre;	//	swap the 1st and the 2nd
        pre->next = curr;
        
        while (curr != NULL && curr->next != NULL) {
        	//	pre is 0-th, curr is 1st node now
            pre->next = curr->next;		//	swap the 1st the 2nd
            curr->next = pre->next->next;
            pre->next->next = curr;
            
            pre = curr;	//	set pre 2nd, curr 3rd node
            curr = pre->next;
        }

        return head;
    }	//	O(n) time, O(1) space
};