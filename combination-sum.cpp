/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
	All numbers (including target) will be positive integers.
	Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
	The solution set must not contain duplicate combinations.

For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3]
*/

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());	//	sort, non-descending order
        
        vector<vector<int>> ans;
        vector<int> ins;
        
        combinationSum(candidates, target, 0, ins, ans);
        
        return ans;
    }	//	O(?) time, O(?) space
    
    void combinationSum(const vector<int> &candidates, const int target,
    		const int pos, vector<int> &ins, vector<vector<int>> &ans) {
        if (target < 0) return;		//	failed
        if (target == 0) {
            ans.push_back(ins);
            return;
        }	//	found !!        
        
        if (pos == candidates.size()) return;	//  out of boundary
        
        //  ignore candidates[pos]
        combinationSum(candidates, target, pos + 1, ins, ans);
        
        //  contain candidates[pos]
        ins.push_back(candidates[pos]);
        combinationSum(candidates, target - candidates[pos], pos, ins, ans);        
        ins.pop_back();
    }
};