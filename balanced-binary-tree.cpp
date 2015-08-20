/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
    bool isBalanced(TreeNode *root) {
        if (root == NULL)   return true;
        
        return depth(root) != -1;
    }	//	O(n) time, O(h) space
    
    int depth(TreeNode *root) {
        if (root == NULL)   return 0;	//	leaf
        
        int left = depth(root->left);
        if (left == -1) return -1;	//	left subtree not balanced
        
        int right = depth(root->right);
        if (right == -1) return -1;	//	right subtree not balanced
        
        if (abs(left - right) > 1)  return -1;	//	root not balanced
        return (left > right) ? (left + 1) : (right + 1);	//	depth 
    }   //  DFS
};