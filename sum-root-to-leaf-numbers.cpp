/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
    int sumNumbers(TreeNode *root) {
        if (root == NULL)   return 0;
        
        int ans = 0;    //  answer
        int num = 0;    //  number on each root-to-leaf path

        sumNumbers(root, num, ans);
        
        return ans;
    }   //  O(n) time, O(h) space
    
    void sumNumbers(TreeNode *root, int num, int &ans) {
        num = num * 10 + root->val;
        
        if (root->left == NULL && root->right == NULL) {
            ans += num;
            return;
        }   //  reach leaf, add num to ans
        
        if (root->left != NULL)     sumNumbers(root->left, num, ans);        
        if (root->right != NULL)    sumNumbers(root->right, num, ans);
    }
};