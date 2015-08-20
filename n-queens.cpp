/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> ans;
        if (n == 0) return ans;
        
        vector<int> pos(n);
        
        solveNQueens(pos, n, 0, ans);
        
        return ans;
    }	//	O(n^3) time, O(n) space
    
    void solveNQueens(vector<int> &pos, int n, int depth, vector<vector<string>> &ans) {
        if (n == depth) {
            vector<string> v(n, string(n, '.'));
            
            for (int i = 0; i < n; i++)	v[i][pos[i]] = 'Q';
            
            ans.push_back(v);
            return;
        }	//	found !!
        
        for (int i = 0; i < n; i++) {
            pos[depth] = i;
            if (check(pos, depth))  solveNQueens(pos, n, depth + 1, ans);
        }
    }
    
    bool check(vector<int> &pos, int depth) {	//	check placement is valid or not so far
        if (depth == 0) return true;
        
        for (int i = 0; i < depth; i++) {            
            if (pos[i] == pos[depth])   return false;	//  same col
            if (abs(pos[i] - pos[depth]) == (depth - i))  return false;	//  diagonal line
            //	no need to check if same row, since we append row by row
        }
        
        return true;
    }	//	O(n) time, O(1) space
};