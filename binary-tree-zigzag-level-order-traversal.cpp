/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ans;        
        if (root == NULL)   return ans;
        
        TreeNode *curr;

        stack<TreeNode*> s1;    //  need 2 stacks !!
        stack<TreeNode*> s2;
        
        s1.push(root);        
        
        while (s1.empty() == false) {
            vector<int> v1;            
            while (s1.empty() == false) {
                curr = s1.top();
                s1.pop();
                
                v1.push_back(curr->val);    //  read from left to right
                //  push elements into s2 from left to right
                if (curr->left != NULL) s2.push(curr->left);
                if (curr->right != NULL) s2.push(curr->right);
            }   //  odd level
            
            ans.push_back(v1);
            
            if (s2.empty() == true)    break;
            
            vector<int> v2;
            while (s2.empty() == false) {
                curr = s2.top();
                s2.pop();
                
                v2.push_back(curr->val);    //  read from right to left
                //  push elements into s1 from right to left
                if (curr->right != NULL) s1.push(curr->right);
                if (curr->left != NULL) s1.push(curr->left);
            }   //  even level
            
            ans.push_back(v2);
        }   //  BFS
        
        return ans;
    }   //  O(n) time, O(n) space
};