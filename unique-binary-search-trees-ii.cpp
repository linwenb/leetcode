/*
Given n, generate all structurally unique BST'st (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST'st shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> ans;

        generateTrees(1, n, ans);
        
        return ans;
    }
    
    void generateTrees(const int st, const int end, vector<TreeNode *> &ans) {
        
        if (st > end) {
            ans.push_back(NULL);
            return;
        }

        TreeNode *root;
        
        for (int i = st; i <= end; i++) {
            vector<TreeNode*> lChild;
            generateTrees(st, i - 1, lChild);
            
            vector<TreeNode*> rChild;
            generateTrees(i + 1, end, rChild);
            
            for (int j = 0; j < lChild.size(); j++) {
                for (int k = 0; k < rChild.size(); k++) {
                    root = new TreeNode(i);
                    
                    root->left = lChild[j];
                    root->right = rChild[k];
                    
                    ans.push_back(root);
                }
            }
        }   //  [st : i-1] in left subtree, i as root, [i+1 : end] in right
    }
};