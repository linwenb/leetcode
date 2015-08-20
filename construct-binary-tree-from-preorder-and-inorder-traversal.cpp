/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0)   return NULL;
        
        return buildTree(preorder, 0, inorder, 0, preorder.size());
    }   //  O(n log n) time, O(h) space
    
    TreeNode *buildTree(const vector<int> &preorder, const int s, const vector<int> &inorder, const int a, const int n) {
        if (n == 1) return new TreeNode(preorder[s]);
        
        TreeNode *root = new TreeNode(preorder[s]);
        
        int i = 0;
        
        while (i < n - 1) {
            if (inorder[a + i] == preorder[s])  break;
            
            i++;
        }   //  find the position of root in inorder[], O(n) time
        
        if (i > 0)  root->left = buildTree(preorder, s + 1, inorder, a, i);
        if (i < n - 1) root->right = buildTree(preorder, s + i + 1, inorder, a + i + 1, n - 1 - i);
        
        return root;
    }
};