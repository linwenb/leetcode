/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        
        if (root == NULL)   return ans;
        
        TreeNode* curr;
        TreeNode* prev = NULL;

        stack<TreeNode*> s;     //  for DFS
        s.push(root);           //  start DFS
                
        while (s.empty() == false) {
            curr = s.top();
            
            if (prev == NULL || prev->left == curr || prev->right == curr) {
                if (curr->left != NULL) {
                    s.push(curr->left);
                }
                else if (curr->right != NULL) {
                    s.push(curr->right);
                }
                else {
                    ans.push_back(curr->val);
                    s.pop();
                }   // no children
            }   //  visit its children first
            else if (curr->left == prev) {
                if (curr->right != NULL) {
                    s.push(curr->right);
                }
                else {
                    ans.push_back(curr->val);
                    s.pop();
                }   // no right child
            }   //  go back from its left
            else {
                ans.push_back(curr->val);
                s.pop();
            }   //  go back from its right
            
            prev = curr;    // update prev
        }
        
        return ans;
    }   //  O(n) time, O(h) space
};