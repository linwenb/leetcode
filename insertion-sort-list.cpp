/*
Sort a linked list using insertion sort.
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
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode *curr, *prev, *tmp;
        
        ListNode *remain = head->next;
        head->next = NULL;

        while (remain != NULL) {
            //  find the position for 'remain' node
            prev = NULL;
            curr = head;
            while(curr != NULL && curr->val <= remain->val) {
                prev = curr;
                curr = curr->next;
            }

            tmp = remain->next;

            //  insert it
            if (prev == NULL) {
                head = remain;
            }   //  as head
            else {
                prev->next = remain;
            }	//	in the middle or as tail
            remain->next = curr;

            remain = tmp;
        }

        return head;
    }      //  O(n^2) time, O(1) space
};