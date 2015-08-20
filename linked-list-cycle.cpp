/*
Given a linked list, determine if it has a cycle in it.

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
    bool hasCycle(ListNode *head) {        
        if (head == NULL)   return false;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            
            //	two pointers meet only when cycle exists
            if (fast == slow)   return true;
        }
        
        return false;	//	no cycle
    }   //  O(n) time, O(1) space
};