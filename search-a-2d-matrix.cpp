/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row = matrix.size();
        if (row == 0)   return false;
        
        int col = matrix.front().size();
        if (col == 0)   return false;
        
        int start = 0;      //  binary search
        int end = row * col - 1;
        int mid;
        
        int midVal;
        
        while (start <= end) {
            mid = start + (end - start) / 2;
            midVal = matrix[mid / col][mid % col];
            
            if (midVal == target) {
                return true;
            }   //  found !
            else if (midVal > target) {
                end = mid - 1;
            }   //  target in left part
            else {
                start = mid + 1;
            }   //  midVal < target, target in right part
        }
        
        return false;   //  not found
    }   //  O(log n + log m) time, O(1) space
};