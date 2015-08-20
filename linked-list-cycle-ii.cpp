/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)   return NULL;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            
            if (fast == slow)   break;
        }	//	detect if there is cycle
        
        if (fast->next == NULL || fast->next->next == NULL) {
            return NULL;
        }	//	no cycle
        
        slow = head;        
        //	now slow at head, fast inside cycle
        //	same distances to the intersection node
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return fast;
    }   //  O(n) time, O(1) space
};