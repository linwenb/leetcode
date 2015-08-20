/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
    	int n = num.size();
        vector<vector<int>> ans;
        permute(num, n, 0, ans);
        return ans;
    }	//	O(n!) time, O(n) space
    
    void permute(const vector<int> &num, const int &n, const int pos, vector<vector<int>> &ans) {
        if (pos == n - 1) {
            ans.push_back(num);
            return;
        }	//	one possible permutation
        
        for (int i = pos; i < n; i++) {
            swap(num[pos], num[i]);		//	put num[i] at pos
            permute(num, n, pos + 1, ans);	//	and permutate the remaining elements
            swap(num[pos], num[i]);		//	swap back
        }
    }
};