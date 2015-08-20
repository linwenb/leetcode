/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
    ListNode *partition(ListNode *head, int x) {
    	if (head == NULL)	return NULL;
    	
        ListNode *lSt = NULL;
        ListNode *lEnd;
        ListNode *rSt = NULL;
        ListNode *rEnd;
        
        while (head != NULL) {
            if (head->val < x) {
                if (lSt == NULL) {
                    lSt = head;
                    lEnd = head;
                }	//	left part is empty
                else {
                    lEnd->next = head;
                    lEnd = head;
                }	//	left part is not empty
            }	//	head->val < x
            else {
                if (rSt == NULL) {
                    rSt = head;
                    rEnd = head;
                }	//	right part is empty
                else {
                    rEnd->next = head;
                    rEnd = head;
                }	//	right part is not empty
            }   //  val >= x

            head = head->next;	//	move forward
        }
        
        if (lSt != NULL) {
            if (rSt != NULL) {
            	lEnd->next = rSt;
            	rEnd->next = NULL;
            }	//	connect two parts

            return lSt;
        }
            
        return rSt;   //  lSt == NULL
    }	//	O(n) time, O(1) space
};