/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

return
[
   [5,4,11,2],
   [5,8,4,5]
]
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> ans;        
        if (root == NULL)   return ans;
        
        vector<int> ins;
        pathSum(root, sum, ins, ans);
    }	//	O(n) time, O(h) space
    
    void pathSum(TreeNode *root, const int &sum, vector<int> &ins, vector<vector<int>> &ans) {
        ins.push_back(root->val);
        
        int newSum = sum - root->val;
        
        if (newSum == 0 && root->left == NULL && root->right == NULL) {
            ans.push_back(ins);
        }	//	found !!
        
        if (root->left != NULL) pathSum(root->left, newSum, ins, ans);
        if (root->right != NULL) pathSum(root->right, newSum, ins, ans);
        
        ins.pop_back();
    }   //	DFS
};