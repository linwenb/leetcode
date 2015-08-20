/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int total = m + n - 2;		//	how many grids except for start and destination        
        if (total < 0)  return 0;   // invalid
        if (total == 0) return 1;   // start and destination, same grid
        
        //  calculate (m+n-2, m-1) causing overflow        
        vector<int> ans(n + 1);		//  use DP
        ans[1] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j + 1] += ans[j]; 	//	from left or up
            }
        }

        return ans.back();	//	ans[n]
    }	//	O(n * m) time, O(n) space
};