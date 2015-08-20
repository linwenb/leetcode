/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size();
        if (row == 0)   return;

        int col = matrix.front().size();
        if (col == 0)    return;
                
        vector<bool> rows(row);
        vector<bool> cols(col);
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }   // find zeroes and store the info in rows and cols
            }
        }
        
        for (int i = 0; i < row; i++) {
            if (rows[i] == true) {
                for (int j = 0; j < col; j++) {
                    matrix[i][j] = 0;
                }
            }   //  ith row has zero
        }
        
        for (int j = 0; j < col; j++) {
            if (cols[j] == true) {
                for (int i = 0; i < row; i++) {
                    matrix[i][j] = 0;
                }
            }   //  jth col has zero
        }
    }   //  O(n * m) time, O(n + m) space
};

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int nRow = matrix.size();
        if (nRow == 0)  return;

        int nCol = matrix.front().size();
        if (nCol == 0)  return;
    
        bool firstRowHasZero = false;
        bool firstColHasZero = false;
            
        for (int j = 0; j < nCol; ++j) {
            if (matrix[0][j] == 0) {
                firstRowHasZero = true;
                break;
            }
        }   // Does first row have zero?
            
        for (int i = 0; i < nRow; ++i) {
            if (matrix[i][0] == 0) {
                firstColHasZero = true;
                break;
            }
        }   // Does first column have zero?
    
        
        for (int i = 1; i < nRow; ++i) {
            for (int j = 1; j < nCol; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }   // find zeroes and store the info in first row and column
    
        
        for (int i = 1; i < nRow; ++i) {
            for (int j = 1; j < nCol; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)  matrix[i][j] = 0;
            }
        }   // set zeroes except the first row and column
    
        // set zeroes for first row and column if needed
        if (firstRowHasZero == true) {
            for (int j = 0; j < nCol; ++j) {
                matrix[0][j] = 0;
            }
        }

        if (firstColHasZero == true) {
            for (int i = 0; i < nRow; ++i) {
                matrix[i][0] = 0;
            }
        }
    }   //  O(n * m) time, O(1) space
};