/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:
	You may only use constant extra space.
	You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7

After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)   return;
        
        TreeLinkNode *leftmost = root;	//	leftmost node on one level
        TreeLinkNode *curr;				//	current node on a level that already done
        
        while (leftmost != NULL) {
            curr = leftmost;
            
            while (curr != NULL) {
                if (curr->left != NULL) {
                    curr->left->next = curr->right;
                    
                    if (curr->next != NULL) {
                        curr->right->next = curr->next->left;
                    }	//	right child points to left child of next node
                }	//	left child points to right child
                
                curr = curr->next;
            }	//	on one level
            
            leftmost = leftmost->left;	//	go to next level
        }	//	foreach level
    }	//	O(n) time, O(1) space
};