/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ans;        
        if (root == NULL) return ans;
        
        int nOneLevel;
        TreeNode *temp;
        vector<int> level;

        queue<TreeNode *> q;    //  for BFS
        q.push(root);           //  start BFS        
        
        while (q.empty() == false) {            
            nOneLevel = q.size();
            
            while (nOneLevel-- > 0) {
                temp = q.front();
                q.pop();
                
                level.push_back(temp->val);
                
                if (temp->left != NULL) q.push(temp->left);
                if (temp->right != NULL) q.push(temp->right);
            }   //  on one level
            
            ans.push_back(level);
            level.clear();
        }
        
        reverse(ans.begin(), ans.end());    //  O(level) time
        return ans;
    }   //  O(n) time, O(n) space
};