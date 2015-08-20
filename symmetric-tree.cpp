/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following is not:
    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode *root) {
        if (root == NULL)   return true;
        
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode *lChild, TreeNode *rChild) {
        if (lChild == NULL && rChild == NULL)  return true; //  reach leaf
        
        if (lChild == NULL || rChild == NULL)  return false;  //  one of them not NULL
        
        if (lChild->val != rChild->val)    return false;  //  both not NULL, but val different
        
        return isSymmetric(lChild->left, rChild->right) && isSymmetric(lChild->right, rChild->left);
    }   //  O(n) time, O(h) space
};