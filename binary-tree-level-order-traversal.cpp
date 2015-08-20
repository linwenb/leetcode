/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> ans;        
        if (root == NULL)   return ans;
        
        int nOneLevel;
        TreeNode *node;

        queue<TreeNode*> q; //  for BFS
        q.push(root);       //  start BFS
        
        while (q.empty() == false) {
            vector<int> v;
            nOneLevel = q.size();            
            
            while (nOneLevel-- > 0) {
                node = q.front();
                q.pop();
                
                v.push_back(node->val);
                
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
            }   //  on one level
            
            ans.push_back(v);
        }
        
        return ans;
    }   //  O(n) time, O(n) space
};