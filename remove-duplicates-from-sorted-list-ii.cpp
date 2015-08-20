/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
        ListNode *fakeHead = new ListNode(0);   //  important
        ListNode *curr = fakeHead;  //  tail of fakeHead
        ListNode *succ = NULL;      //  succ node of head
        
        while (head != NULL) {
            succ = head->next;
            
            while (succ != NULL && succ->val == head->val) {
                succ = succ->next;
            }   //  find the next pointer with val different from head's
            
            if (head->next == succ) {
                curr->next = head;
                curr = head;
            }   //  head is not duplicate number, append it to result list
            
            head = succ;    //  move forward
        }
        
        curr->next = NULL;  //  isolate the result list
        
        curr = fakeHead->next;
        delete fakeHead;

        return curr;
    }   //  O(n) time, O(1) space
};