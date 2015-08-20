/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int row = obstacleGrid.size();
        if (row == 0)   return 0;
        
        int col = obstacleGrid.front().size();
        if (col == 0)   return 0;
        
        vector<int> ans(col + 1);	//	DP, row by row
        ans[1] = 1;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (obstacleGrid[i][j] == 1) {
                    ans[j + 1] = 0;
                }   //  obstacle
                else {
                    ans[j + 1] += ans[j];
                }   //  empty space, could from left and up
            }
        }
        return ans.back();	//	ans[col]
    }	//	O(n * m) time, O(m) space
};