/*
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.

For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> ans;
        
        int n = S.size();
        int total = pow(2.0, n);
        int k;
        
        sort(S.begin(), S.end());
        
        for (int i = 0; i < total; i++) {
            k = 1;
            vector<int> sub;

            for (int j = 0; j < n; j++) {
                if (i & k)  sub.push_back(S[j]);
                
                k <<= 1;
            }   //  decide if insert jth elements

            ans.push_back(sub);
        }   //  2^n subsets
        
        return ans;
    }   //  O(n * 2^n) time, O(n) space
};