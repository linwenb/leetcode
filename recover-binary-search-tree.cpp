/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
    void recoverTree(TreeNode *root) {
        /*
        1. Given {1, 4, 3, 7, 9}, find pair 4(!<=)3, swap this pair
        2. Given {1, 9, 4, 5, 3, 10}, first pair 9(!<=)4 and second pair 5(!<=)3, swap pair 9(!<=)3
        3. only in two above (general) cases, tranverse BST inorder to get above sequence.
        */        
        if (root == NULL)   return;
        
        TreeNode *prev = new TreeNode(INT_MIN);		//	previous element in inorder
        TreeNode *first = NULL;		//	first element swapped
        TreeNode *second = NULL;	//	second element swapped
        
        recoverTree(root, prev, first, second);
        
        if (first != NULL) {
            swap(first->val, second->val);
        }	//	mistake exists
    }	//	O(n) time, O(h) space
    
    void recoverTree(TreeNode* root, TreeNode* &prev, TreeNode* &first, TreeNode* &second) {
        if (root == NULL)   return;
        
        recoverTree(root->left, prev, first, second);
        
        if (prev->val > root->val) {
            if (first == NULL)  first = prev;	//	first element swapped
            second = root;		//	second element swapped, need to find the last one
        }	//	not BST
        
        prev = root;
        
        recoverTree(root->right, prev, first, second);
    }	//	inorder, prev is pointer reference !!!!!!!
};