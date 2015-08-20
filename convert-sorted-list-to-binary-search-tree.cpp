/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL)   return NULL;
        if (head->next == NULL) return new TreeNode(head->val);
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }   //  slow->next is middle node
        
        ListNode *mid = slow->next;
        slow->next = NULL;          // break into two lists
        
        TreeNode *root = new TreeNode(mid->val);    //  root node
        
        root->left = sortedListToBST(head);         //  left subtree
        root->right = sortedListToBST(mid->next);   //  right subtree
        
        return root;
    }   //  O(n log n) time, O(h) space
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL)   return NULL;
        
        ListNode *p = head;
        int len = 0;
        
        while (p != NULL) {
            p = p->next;
            len++;
        }

        return sortedListToBST(head, 1, len);
    }   //  O(n) time, O(h) space
    
    TreeNode *sortedListToBST(ListNode* &head, const int st, const int end) {
        if (st > end)   return NULL;
        
        int mid = st + (end - st) / 2;
        
        TreeNode *lChild = sortedListToBST(head, st, mid - 1);
        
        TreeNode *root = new TreeNode(head->val);
        
        head = head->next;  //  because head is reference pointer, move head and construct root
        
        TreeNode *rChild = sortedListToBST(head, mid + 1, end);
        
        root->left = lChild;
        root->right = rChild;
        
        return root;
    }   //  in bottom-up way
};