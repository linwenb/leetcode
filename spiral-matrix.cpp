/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5].
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
    	vector<int> ans;

        int m = matrix.size();  //  row number
        if (m == 0) return ans;
        
        int n = matrix.front().size();  //  col number
        if (n == 0) return ans;
        
        int x = 0;
        int y = 0;
        int level = 0;
        int total = n * m;
        
        while (total > 0) {
            if (total == 1) {
                ans.push_back(matrix[x][y]);
                break;
            }	//	last sole value at the center
            
            while (total > 0 && y < n - 1 - level) {
            	ans.push_back(matrix[x][y++]);
            	total--;
            }	//	right          
            while (total > 0 && x < m - 1 - level) {
            	ans.push_back(matrix[x++][y]);
            	total--;
            }	//	down
            while (total > 0 && y > level) {
            	ans.push_back(matrix[x][y--]);
            	total--;
            }	//  left
            while (total > 0 && x > level) {
            	ans.push_back(matrix[x--][y]);
            	total--;
            }	//  up
            
            x++;
            y++;
            level++;	//	inner level
        }
        
        return ans;
    }	//	O(n * m) time, O(1) space
};