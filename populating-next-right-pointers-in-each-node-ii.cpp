/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:
You may only use constant extra space.

For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
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
        TreeLinkNode *curr;		//	current node on a level that already done
        TreeLinkNode *prev;		//	tail node on a working level
        
        while (leftmost != NULL) {
            curr = leftmost;

            leftmost = NULL;
            
            while (curr != NULL) {
                if (curr->left != NULL) {
                    leftmost = curr->left;
                    
                    if (curr->right != NULL) {
                        curr->left->next = curr->right;
                        prev = curr->right;
                    }
                    else {
                        prev = curr->left;
                    }
                    
                    curr = curr->next;
                    break;
                }
                
                if (curr->right != NULL) {
                    leftmost = curr->right;
                    prev = curr->right;
                    
                    curr = curr->next;
                    break;
                }
                
                curr = curr->next;
            }	//  find leftmost for next level and first prev
            
            while (curr != NULL) {
                if (curr->left != NULL) {
                    prev->next = curr->left;
                    prev = prev->next;
                }
                
                if (curr->right != NULL) {
                    prev->next = curr->right;
                    prev = prev->next;
                }
                
                curr = curr->next;
            }	//	on one level
        }	//	foreach level
    }   //  O(n) time, O(1) space
};