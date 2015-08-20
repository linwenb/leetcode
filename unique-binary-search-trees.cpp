/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

class Solution {
public:
    int numTrees(int n) {
        if (n <= 2) return n;
        
        //  n >= 3
        vector<int> ans(n + 1);     //  DP
        ans[0] = 1;
        ans[1] = 1;
        ans[2] = 2;
        
        for (int i = 3; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                ans[i] += ans[j] * ans[i - 1 - j];
            }   //  j nodes in left subtree, (i-1-j) in right
        }
        
        return ans.back();	//	ans[n]
    }   //  O(n^2) time, O(n) space
};