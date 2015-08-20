/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
    	int n = num.size();
        vector<vector<int>> ans;
        
        permuteUnique(num, n, 0, ans);
        
        return ans;
    }	//	O(n!) time, O(n^2) space
    
    void permuteUnique(const vector<int> &num, const int &n, const int pos, vector<vector<int>> &ans) {
        if (pos == n - 1) {
            ans.push_back(num);
            return;
        }	//	one possible unique permutation
        
        unordered_set<int> st;	//	help to check duplicate
        
        for (int i = pos; i < n; i++) {
            if (st.find(num[i]) != st.end()) continue;	//	duplicate, already done
            
            st.insert(num[i]);
            
            swap(num[i], num[pos]);		//	put num[i] at pos
            permuteUnique(num, n, pos + 1, ans);	//	continue on the remaining elements
            swap(num[i], num[pos]);		//	swap back
        }
    }
};