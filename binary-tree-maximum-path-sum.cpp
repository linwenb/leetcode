/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3

Return 6.
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
    int maxPathSum(TreeNode *root) {
        if (root == NULL)   return 0;
        
        int subans = 0;
        return maxPathSum(root, subans);
    }   //  O(n) time, O(h) space

    int maxPathSum(TreeNode *root, int &subans) {
        if (root == NULL)   return INT_MIN;
        
        int leftSubans = 0;     //  subans in left subtree
        int rightSubans = 0;    //  subans in right subtree

        int leftAns = maxPathSum(root->left, leftSubans);
        int rightAns = maxPathSum(root->right, rightSubans);

        subans = root->val; //  longest path starting from root

        if (leftSubans > 0 && rightSubans > 0) {
            subans += max(leftSubans, rightSubans);
        }   //  both left and right are not NULL
        else if (leftSubans > 0) {
            subans += leftSubans;
        }   //  left is not NULL
        else if (rightSubans > 0) {
            subans += rightSubans;
        }   //  right is not NULL
        
        int ans = root->val;    //  max path sum including root
        if (leftSubans > 0)     ans += leftSubans;
        if (rightSubans > 0)    ans += rightSubans;
        
        //  return the max of ans, leftAns, rightAns
        return max(ans, max(leftAns, rightAns));
    }   //  DFS
};