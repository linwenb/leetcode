/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        vector<int> row(9, 0);
        vector<int> col(9, 0);
        vector<int> sec(9, 0);
        
        initialize(board, row, col, sec);        
        solveSudoku(board, 0, row, col, sec);
    }	//	O(1) time, O(1) space
    
    bool solveSudoku(vector<vector<char> > &board, const int pos, vector<int> &row, vector<int> &col, vector<int> &sec) {
        if (pos == 81)  return true;	//	finished !!
        
        int n = pos / 9;	//	n-th row
        int m = pos % 9;	//	m-th col
        
        if (board[n][m] != '.') return solveSudoku(board, pos + 1, row, col, sec);	// already filled
        
        int secNo = n / 3 * 3 + m / 3;
        int mask;
        
        for (int i = 0; i < 9; i++) {
            mask = 1 << i;
            
            if (checkValid(row, col, sec, n, m, secNo, mask) == true) {
                board[n][m] = '1' + i;
                updateMask(row, col, sec, n, m, secNo, mask);	//	update appearance info
                
                if (solveSudoku(board, pos + 1, row, col, sec) == true)	return true;	//  DFS
                
                //  number i does not work
                board[n][m] = '.';	//	set back to '.'
                updateMask(row, col, sec, n, m, secNo, mask);	//	appearance info set back
            }	//	board[n][m] set i is valid
        }	//  try 1-9
        
        return false;	//  this path is invalid
    }	//  DFS
    
    void updateMask(vector<int> &row, vector<int> &col, vector<int> &sec,
    		const int i, const int j, const int k, const int mask) {
        //  update the appearance of 1-9 in each row, col and section
        row[i] ^= mask;
        col[j] ^= mask;
        sec[k] ^= mask;
    }
    
    bool checkValid(vector<int> &row, vector<int> &col, vector<int> &sec,
            const int i, const int j, const int k, const int mask) {
        //  check if the board is valid after setting board[i][j]
        if ((row[i] & mask) == 0 && (col[j] & mask) == 0 && (sec[k] & mask) == 0)	return true;
            
        return false;	//	invalid
    }
    
    void initialize(const vector<vector<char>> &board, vector<int> &row, vector<int> &col, vector<int> &sec) {
        //  record the origin appearance of 1-9 in each row, column and section
        int secNo;
        int mask;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                	//	rowNo is i
                	//	colNo is j
                    secNo = i / 3 * 3 + j / 3;
                    
                    mask = 1 << (board[i][j] - '1');
                    updateMask(row, col, sec, i, j, secNo, mask);
                }
            }
        }
    }
};