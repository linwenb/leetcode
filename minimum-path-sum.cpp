/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {      
        int row = grid.size();
        if (row == 0)	return 0;
                
        int col = grid.front().size();
        if (col == 0)	return 0;

        vector<int> ans(col + 1, INT_MAX);	//  DP, process row by row
        ans[1] = 0;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ans[j + 1] = min(ans[j], ans[j + 1]) + grid[i][j];
            }	//  from left or up
        }
        
        return ans.back();
    }	//	O(n * m) time, O(m) space 
};