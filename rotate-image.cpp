/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int temp;
        
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - 1 - i; j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];					//	right to up
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];	//	down to right
                matrix[n - 1 - i][n - 1 -j] = matrix[j][n - 1 - i];		//	left to down
                matrix[j][n - 1 - i] = temp;							//	up to left
            }
        }	//	each level
    }	//	O(n^2) time, O(1) space
};