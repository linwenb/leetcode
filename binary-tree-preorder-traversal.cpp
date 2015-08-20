/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;

        if (root == NULL) return ans;        
        
        TreeNode *curr;

        stack<TreeNode*> s;     //  for DFS
        s.push(root);           //  start DFS
        
        while (s.empty() == false) {
            curr = s.top();
            s.pop();
            
            ans.push_back(curr->val);

            if (curr->right != NULL)  s.push(curr->right);
            if (curr->left != NULL)  s.push(curr->left);
        }
        
        return ans;
    }   //  O(n) time, O(h) space
};