/*
Given a binary tree, flatten it to a linked list in-place.

For example,

Given

         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
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
    void flatten(TreeNode *root) {
        if (root == NULL)   return;
        
        helper(root);
    }   //  O(n) time, O(h) space
    
    TreeNode* helper(TreeNode *root) {
        TreeNode *tail = root;
        
        TreeNode *lNode = root->left;
        TreeNode *rNode = root->right;
        
        if (lNode != NULL) {
            root->left = NULL;
            root->right = lNode;
            
            tail = helper(lNode);
        }
        
        if (rNode != NULL) {
            tail->right = rNode;
            
            tail = helper(rNode);
        }
        
        return tail;
    }
};  //  recursive

class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode *prev;
        
        while (root != NULL) {
            if (root->left != NULL) {
                //  find rightmost node in left subtree
                prev = root->left;
                while (prev->right != NULL) prev = prev->right; 
                
                prev->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            
            root = root->right;     //  move forward
        }
    }   //  O(n) time, O(1) space
};  //  iterative