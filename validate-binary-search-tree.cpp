/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

	The left subtree of a node contains only nodes with keys less than the node's key.
	The right subtree of a node contains only nodes with keys greater than the node's key.
	Both the left and right subtrees must also be binary search trees.
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
    bool isValidBST(TreeNode *root) {
        if (root == NULL)   return true;    //  empty tree
        
        int prev = INT_MIN;

        return isValidBST(root, prev);
    }	//	O(n) time, O(h) space
    
    bool isValidBST(TreeNode *root, int &prev) {    //  reference value, could be changed
        
        if (root->left != NULL && isValidBST(root->left, prev) == false) {
            return false;
        }	//	left subtree is not BST
            
        if (prev > root->val)  return false;	//	not BST
        
        prev = root->val;   //  update prev
        
        if (root->right != NULL && isValidBST(root->right, prev) == false) {
            return false;
        }	//	right subtree is not BST

        return true;	//	BST
    }	//	inorder
};