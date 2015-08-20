/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) return NULL;
        
        int n = 0;	//	length of list
        ListNode* fast = head;

        while (fast != NULL) {
            fast = fast->next;
            n++;
        }	//	find n

        k = k % n;        
        if (k == 0) return head;	//	no need to rotate
        
        fast = head;
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }	//	fast points to kth node
        
        ListNode* slow = head;
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }	//	fast reaches end, slow points to last kth node
        
        ListNode* newHead = slow->next;
        fast->next = head;
        slow->next = NULL;
        
        return newHead;
    }	//	O(n) time, O(1) space
};