/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
        
        ListNode *p = head;
        int curVal = p->val;
        
        while (p->next != NULL) {
            if (p->next->val == curVal) {
                p->next = p->next->next;
            }   //  duplicate, ignore it
            else {
                p = p->next;
                curVal = p->val;
            }   //  different, move forward
        }

        return head;
    }   //  O(n) time, O(1) space
};