/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        return addTwoNumbers(l1, l2, false);
    }   //  O(n + m) time, O(n + m) space
    
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, bool carry) {
        if (l1 == NULL) return addOneNumber(l2, carry);
        if (l2 == NULL) return addOneNumber(l1, carry);
        
        ListNode *p = new ListNode(l1->val + l2->val);
        
        if (carry)  p->val += 1;
        
        if (p->val > 9) {
            p->val -= 10;
            p->next = addTwoNumbers(l1->next, l2->next, true);
        }
        else {
            p->next = addTwoNumbers(l1->next, l2->next, false);
        }
        
        return p;
    }
    
    ListNode *addOneNumber(ListNode *node, bool carry) {
        if (node == NULL) {
            if (carry == false)  return NULL;
            
            return new ListNode(1);
        }
        
        ListNode *p = new ListNode(node->val);
        
        if (carry)  p->val += 1;
        
        if (p->val > 9) {
            p->val -= 10;
            p->next = addOneNumber(node->next, true);
        }
        else {
            p->next = addOneNumber(node->next, false);
        }
        
        return p;
    }
};  //  recursive

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *fakeHead = new ListNode(0);
        ListNode *curr = fakeHead;
        
        int carry = 0;
        int t;  //  temp
        
        while (l1 != NULL && l2 != NULL) {
            t = l1->val + l2->val + carry;
            
            if (t > 9) {
                t -= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            
            curr->next = new ListNode(t);
            
            l1 = l1->next;
            l2 = l2->next;
            curr = curr->next;
        }
        
        while (l1 != NULL) {
            t = l1->val + carry;
            
            if (t > 9) {
                t -= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            
            curr->next = new ListNode(t);
            
            l1 = l1->next;
            curr = curr->next;
        }
        
        while (l2 != NULL) {
            t = l2->val + carry;
            
            if (t > 9) {
                t -= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            
            curr->next = new ListNode(t);
            
            l2 = l2->next;
            curr = curr->next;            
        }
        
        if (carry == 1) curr->next = new ListNode(1);
        
        curr = fakeHead->next;
        delete fakeHead;
        return curr;
    }   //  O(n + m) time, O(1) space
};  //  iterative