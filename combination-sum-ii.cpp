/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
	All numbers (including target) will be positive integers.
	Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
	The solution set must not contain duplicate combinations.

For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> ans;
        
        if (num.size() == 0) return ans;
        
        vector<int> newNum;
        unordered_map<int, int> mpCnt;
        initialize(num, newNum, mpCnt);
        
        vector<int> ins;
        combinationSum2(newNum, target, 0, ins, ans, mpCnt);

        return ans;
    }	//	O(?) time, O(?) space
    
    void initialize(const vector<int> &num, vector<int> &newNum, unordered_map<int, int> &mpCnt) {
        unordered_map<int, int>::iterator p;
        
        for (int i = 0; i < num.size(); i++) {
            p = mpCnt.find(num[i]);
            if (p == mpCnt.end()) {
                mpCnt[num[i]] = 1;
                newNum.push_back(num[i]);
            }	//	this number not visited yet
            else {
                p->second++;
            }	//	duplicate
        }
        
        sort(newNum.begin(), newNum.end());	//	non-descending order
    }	//	O(n log n) time, O(n) space
    
    void combinationSum2(const vector<int> &newNum, const int target, const int pos,
            vector<int> &ins, vector<vector<int>> &ans, unordered_map<int, int> &mpCnt) {
        if (target < 0) return;	//	failed
        if (target == 0) {
            ans.push_back(ins);
            return;
        }	//	found
                
        if (pos == newNum.size()) return;	//  out of boundary

        //  ignore newNum[pos]
        combinationSum2(newNum, target, pos + 1, ins, ans, mpCnt);
        
        //  contain newNum[pos] if there is quota
        if (mpCnt[newNum[pos]] > 0) {
            mpCnt[newNum[pos]]--;
            ins.push_back(newNum[pos]);
            combinationSum2(newNum, target - newNum[pos], pos, ins, ans, mpCnt);
            ins.pop_back();
            mpCnt[newNum[pos]]++;
        }
    }
};