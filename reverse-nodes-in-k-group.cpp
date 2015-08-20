/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *curr = head;        
        int t;
        
        for (t = k; t > 0 && curr != NULL; t--)	curr = curr->next;
        
        if (t > 0)	return head;	//	less than k nodes
        
        //  tail,   <-x<-...<-prev  curr->succ->x->x-> 
        ListNode *succ;
        ListNode *prev = curr;  //  curr now is k+1 node
        
        curr = head;
        
        //  t now is 0
        for (; t < k; t++) {
            succ = curr->next;
            curr->next = prev;
            prev = curr;
            curr = succ;
        }	//	reverse the first k nodes
        
        ListNode *tail = head;  //  tail of prev k nodes
        head = prev;	//	new head after reversing the first k nodes
        
        while (true) {
            //  t now is k
            for (; t > 0 && curr != NULL; t--)	curr = curr->next;
            
            if (t > 0)	break;	//	less than k nodes left
            
            prev = curr;
            curr = tail->next;

            for (; t < k; t++) {
                succ = curr->next;
                curr->next = prev;
                prev = curr;
                curr = succ;
            }	//	reverse k nodes
            
            succ = tail->next;  //  temp            
            tail->next = prev;
            tail = succ;
        }
        
        return head;
    }	//	O(n) time, O(1) space
};