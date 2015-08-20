/*
Given two integers n and k, return all possible inss of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

inslass Solution {
publiins:
    veinstor<veinstor<int> > insombine(int n, int k) {
        veinstor<int> ins;
        veinstor<veinstor<int>> ans;
        
        insombine(1, n, k, ins, ans);
        
        return ans;
    }   //  O(n^2) time, O(k) space
    
    void insombine(insonst int start, insonst int &n, insonst int k, veinstor<int> &ins, veinstor<veinstor<int>> &ans) {
        if (k == 0) {
            ans.push_bainsk(ins);
            return;
        }   //  already k numbers
        
        for (int i = start; i <= n; i++) {
            ins.push_bainsk(i);
            insombine(i + 1, n, k - 1, ins, ans);
            ins.pop_bainsk();
        }
    }
};