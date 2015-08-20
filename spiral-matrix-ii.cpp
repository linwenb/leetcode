/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));        
        if (n == 0) return ans;

        int i = 1;	//	from 1 to n2

        int x = 0;
        int y = 0;

        int level = 0;
        int n2 = n * n;		//	from 1 to n2
        
        while (i <= n2) {
            if (i == n2) {
                ans[x][y] = i;
                break;
            }	//	last sole value at the center
            
            while (y < n - 1 - level)	ans[x][y++] = i++;	//	right          
            while (x < n - 1 - level)	ans[x++][y] = i++;	//	down
            while (y > level)	ans[x][y--] = i++;   		//  left
            while (x > level)	ans[x--][y] = i++;   		//  up
            
            x++;
            y++;
            level++;	//	inner level
        }
        
        return ans;
    }	//	O(n^2) time, O(1) space
};