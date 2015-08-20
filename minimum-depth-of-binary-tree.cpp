/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode *root) {
        if (root == NULL)   return 0;
        
        int ans = 0;    //  depth
        int nOneLevel;  //  number of nodes on one level
        
        TreeNode *p;    //  temp
        
        queue<TreeNode*> q; //  for BFS
        q.push(root);       //  start BFS
        
        while (q.empty() == false) {
            nOneLevel = q.size();
            ans++;      //  one more level
            
            while (nOneLevel-- > 0) {
                p = q.front();
                q.pop();
                
                if (p->left == NULL && p->right == NULL)  return ans;   //  found !!
                
                if (p->left != NULL)    q.push(p->left);
                if (p->right != NULL)   q.push(p->right);
            }
        }
    }   //  O(h) time, O(n) space
};