/*
Given inorder and postorder traversal of a tree, construct the binary tree.

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() == 0)   return NULL;
        
        return buildTree(inorder, 0, postorder, 0, inorder.size());
    }   //  O(n log n) time, O(h) space
    
    TreeNode *buildTree(const vector<int> &inorder, int s, vector<int> &postorder, int a, int n) {
        if (n == 1) return new TreeNode(inorder[s]);
        
        int val = postorder[a + n - 1];
        
        TreeNode *root = new TreeNode(val);
        
        int i = 0;
        
        while (i < n - 1) {
            if (inorder[s + i] == val)  break;
            
            i++;
        }   //  find the position of root in inorder[], O(n) time
        
        if (i > 0)  root->left = buildTree(inorder, s, postorder, a, i);
        if (i < n - 1) root->right = buildTree(inorder, s + i + 1, postorder, a + i, n - 1 - i);
        
        return root;
    }
};