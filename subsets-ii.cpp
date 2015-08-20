/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
	Elements in a subset must be in non-descending order.
	The solution set must not contain duplicate subsets.

For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
    	int n = S.size();
        vector<vector<int>> ans;
        
        ans.push_back(vector<int>());   //  empty subset
        
        if (n == 0)  return ans;
        
        sort(S.begin(), S.end());	//	help to check duplicate elements
        
        int lastElem = S[0] - 1;	//  last element processed
        int lastSize = 0;			//	how many subsets generated so far
        int startPos;
        
        for (int i = 0; i < n; i++) {
            if (S[i] == lastElem) {
            	//  only consider the subsets made by the previous element !!!
            	//	to avoid generating duplicate subsets !!!
                startPos = lastSize;
            }	//	current is a duplicate element
            else {
                startPos = 0;
                lastElem = S[i];    //  update last element
            }	//	a new element
            
            lastSize = ans.size();	//  update
            
            for (int j = startPos; j < lastSize; j++) {
                ans.push_back(ans[j]);
                ans.back().push_back(lastElem);
            }	//	foreach existing subset, insert current element generating new subset !!!
        }
        
        return ans;
    }	//	O(2^n) time, O(1) space
};