/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
    int maxDepth(TreeNode *root) {
        if (NULL == root) return 0;
        
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);
        
        return (lDepth > rDepth)? (lDepth + 1) : (rDepth + 1);
    }	//	O(n) time, O(h) space
};