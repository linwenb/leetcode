/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
    	int k = lists.size();   //  k sorted linked lists
        if (k == 0)  return NULL;
        
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;	//	smaller value has higher priority
        
        for (int i = 0; i < k; i++) {
            if (lists[i] != NULL)   pq.push(lists[i]);
        }	//	push all the heads of lists into priority queue
        
        ListNode *fakeHead = new ListNode(0);
        ListNode *curr = fakeHead;
        ListNode *temp = NULL;
        
        while (pq.empty() == false) {
            curr->next = pq.top();
            pq.pop();
            
            curr = curr->next;
            
            if (curr->next != NULL) pq.push(curr->next);    //  push the new head
        }
        
        curr = fakeHead->next;
        delete fakeHead;
        
        return curr;
    }	//	O(n log k) time, O(k) space
    
    struct cmp {
        bool operator() (const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }	//	swap if value of a is larger
    };
};