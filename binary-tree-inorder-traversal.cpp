/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode *root) {
        if (root == NULL) return vector<int>();
        
        vector<int> ans = inorderTraversal(root->left);	//	visit left subtree
        
        ans.push_back(root->val);	//	then root
        
        vector<int> temp = inorderTraversal(root->right);	//	finally right subtree
        
        ans.insert(ans.end(), temp.begin(), temp.end());
        
        return ans;
    }	//	O(n) time, O(h) space
};	//	Recursive

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;

        if (root == NULL) return ans;
        
        stack<TreeNode*> s;
        TreeNode *current = root;
        
        while (s.empty() == false || current != NULL) {
            if (current != NULL) {
                s.push(current);
                current = current->left;
            }	//	go to leftmost
            else {
                current = s.top();
                s.pop();
                ans.push_back(current->val);
                current = current->right;
            }	//	finished left subtree, visit root, then right subtree
        }
        
        return ans;
    }	//	O(n) time, O(h) space
};	//	iterative