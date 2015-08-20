/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int rowElem, row, preRow;
        int colElem, col, preCol;
        int secElem, sec, preSec;
        
        for (int i = 0; i < 9; i++) {
            row = preRow = 0;
            col = preCol = 0;
            sec = preSec = 0;
            
            for (int j = 0; j < 9; j++) {
                rowElem = board[i][j] - '0';
                colElem = board[j][i] - '0';
                secElem = board[i/3*3 + j/3][(i%3)*3 + (j%3)] - '0';
                
                //  ignore '.'
                if (rowElem > 0)    row ^= 1 << rowElem;
                if (colElem > 0)    col ^= 1 << colElem;
                if (secElem > 0)    sec ^= 1 << secElem;
                
                //  occure twice, bit set to 0, number would be smaller, false
                if (row < preRow || col < preCol || sec < preSec)	return false;
                
                preRow = row;
                preCol = col;
                preSec = sec;
            }
        }
        
        return true;
    }	//	O(1) time, O(1) space
};