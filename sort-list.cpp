/*
Sort a linked list in O(n log n) time using constant space complexity.
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
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode *fast = head->next;
        ListNode *slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }	//	to find the middle node !!!!
        
        fast = slow->next;  //  head of right part
        slow->next = NULL;  //  separate two parts
        
        ListNode *lHead = sortList(head);
        ListNode *rHead = sortList(fast);
        
        return mergeList(lHead, rHead);
    }   //  O(n log n) time, O(h) space
    
    ListNode *mergeList(ListNode *lHead, ListNode *rHead) {
        ListNode *fakeHead = new ListNode(0);
        ListNode *curr = fakeHead;
        
        while (lHead != NULL && rHead != NULL) {
            if (lHead->val < rHead->val) {
                curr->next = lHead;
                lHead = lHead->next;
            }
            else {
                curr->next = rHead;
                rHead = rHead->next;
            }
            
            curr = curr->next;
        }
        
        if (lHead != NULL)  curr->next = lHead;
        if (rHead != NULL)  curr->next = rHead;
        
        curr = fakeHead->next;
        delete fakeHead;
        
        return curr;
    }   //  O(n) time, O(1) space
};