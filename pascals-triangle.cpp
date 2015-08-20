/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> ans;        
        if (numRows == 0)   return ans;
        
        vector<int> row;

        row.push_back(1);	//	first row        
        ans.push_back(row);
        
        for (int i = 0; i < numRows - 1; i++) {
            row.clear();

            row.push_back(1);	//	the first element is always 1
            for (int j = 0; j < i; j++) row.push_back(ans[i][j] + ans[i][j + 1]);
            row.push_back(1);	//	the last element is always 1
            
            ans.push_back(row);
        }
        
        return ans;
    }   //  O(n^2) time, O(n) space
};