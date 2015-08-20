/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num, 0, num.size() - 1);
    }   //  O(n) time, O(h) space
    
    TreeNode *sortedArrayToBST(const vector<int> &num, const int s, const int e) {
        if (s > e)  return NULL;
        
        int m = s - (s - e) / 2;

        TreeNode *root = new TreeNode(num[m]);
        
        root->left = sortedArrayToBST(num, s, m - 1);
        root->right = sortedArrayToBST(num, m + 1, e);
        
        return root;
    }   //  in top-down way
};