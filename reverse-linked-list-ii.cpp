/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == 1) return reverseBetween(head, n);
        
        ListNode *p = head;
        for (int i = 1; i < m - 1; i++)	p = p->next;	//	go to (m-1)th node
        
        p->next = reverseBetween(p->next, n - m + 1);
        
        return head;
    }	//	O(n) time, O(1) space
    
    ListNode *reverseBetween(ListNode *head, int n) {
        if (n == 1) return head;
        
        ListNode *curr = head;
        ListNode *follow;
        ListNode *prev = NULL;
        
        for (int i = 0; i < n; i++) {
            follow = curr->next;
            curr->next = prev;
            prev = curr;
            curr = follow;
        }
        
        head->next = curr;
        
        return prev;
    }	//	reverse n nodes starting from head, O(n) time, O(1) space
};