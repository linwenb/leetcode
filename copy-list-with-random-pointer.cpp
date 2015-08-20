/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> m;  //  visiting or visited nodes
        
        return copyRandomList(head, m);
    }   //  O(n) time, O(n) space
    
    RandomListNode *copyRandomList(RandomListNode *head, unordered_map<RandomListNode*, RandomListNode*> &m) {
        if (head == NULL)   return NULL;
        if (m.find(head) != m.end())    return m[head];	//	already copied head node
        
        RandomListNode *p = new RandomListNode(head->label);	//	start copying head node

        m[head] = p;    // visiting
        
        p->next = copyRandomList(head->next, m);
        p->random = copyRandomList(head->random, m);
        
        return p;
    }
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)   return NULL;
        
        RandomListNode *fakeHead = new RandomListNode(0);
        
        RandomListNode *curr = head;    //  visit original list
        RandomListNode *p = fakeHead;
        RandomListNode *temp;
        
        unordered_map<RandomListNode*, RandomListNode*> mp;  //  can locate copied node fast
        
        while (curr != NULL) {
            temp = new RandomListNode(curr->label);
            
            p->next = temp;
            mp[curr] = temp;
            
            curr = curr->next;
            p = temp;
        }   //  copy list nodes first
        
        curr = head;
        p = fakeHead->next;
        
        while (curr != NULL) {
            if (curr->random != NULL) p->random = mp[curr->random];
            
            curr = curr->next;
            p = p->next;
        }   //  copy random pointers
        
        p = fakeHead->next;
        delete fakeHead;
        
        return p;
    }   //  O(n) time, O(1) space
};