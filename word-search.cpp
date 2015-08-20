/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int n = word.size();
        if (n == 0)   return true;

        int N = board.size();
        if (N == 0)  return false;
        
        int M = board.front().size();
        if (M == 0)  return false;
        
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (word[0] == board[i][j] && exit(board, word, 0, i, j, visited)) {
                    return true;
                }   //  start from each position, do BFS
            }
        }
        
        return false;   //  not exist
    }   //  O(n * N * M) time, O(NM) space
    
    bool exit(const vector<vector<char>> &board, const string &word,
            const int pos, const int x, const int y, vector<vector<bool>> &visited) {
        if (pos == word.size()) return true;    //  reach end, found !!
                
        if (x < 0 || x == board.size()) return false;   //  out of boundry
        if (y < 0 || y == board[0].size()) return false;
                
        if (visited[x][y])  return false;   //  already visited
        
        if (word[pos] != board[x][y])   return false;   //  not match
        
        visited[x][y] = true;   //  match, then start visiting
        
        if (exit(board, word, pos + 1, x - 1, y, visited))   return true;   //  down
        if (exit(board, word, pos + 1, x + 1, y, visited))   return true;   //  up
        if (exit(board, word, pos + 1, x, y - 1, visited))   return true;   //  left
        if (exit(board, word, pos + 1, x, y + 1, visited))   return true;   //  right
        
        visited[x][y] = false;  //  clear visit record
        return false;   //  not exist
    }   //  O(n) time, O(n) space
};