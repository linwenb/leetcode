/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
    Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL) return;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }	//	to find the middle node
        
        fast = slow->next;  //  fast points to the middle node
        slow->next = NULL;  //  break into two lists
        
        reverse(fast);  // reverse the second half one
        
        slow = head;
        ListNode *temp;
        
        while (slow != NULL) {
            temp = slow->next;
            slow->next = fast;
            slow = temp;
            
            if (fast != NULL) {
                temp = fast->next;
                fast->next = slow;
                fast = temp;
            }
        }   // merge two lists
    }   //  O(n) time, O(1) space
    
    void reverse(ListNode* &head) {
        if (head == NULL)   return;
        
        ListNode *p = head;
        ListNode *temp;
        head = NULL;
                
        while (p != NULL) {
            temp = p->next;
            p->next = head;
            head = p;
            p = temp;
        }   // ...<-head   p   temp->...
    }	//	reverse linked list, O(n) time, O(1) space
};