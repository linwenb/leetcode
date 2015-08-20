/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int N = board.size();
        if (N == 0) return;
        
        int M = board.front().size();
        if (M == 0) return;
        
        //  label safe 'O's (on the edge) as 'V'
        for (int i = 0; i < M; i++) {
            if (board[0][i] == 'O') bfs(board, 0, i);
            if (board[N-1][i] == 'O') bfs(board, N - 1, i);
        }
        
        for (int i = 0; i < N; i++) {
            if (board[i][0] == 'O') bfs(board, i, 0);
            if (board[i][M-1] == 'O') bfs(board, i, M - 1);
        }

        //  flipping all 'O's in surrounded region into 'X', safe 'O's back into 'O'
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] != 'X') {
                    board[i][j] = (board[i][j] == 'V') ? 'O' : 'X';
                }
            }
        }
    }   //  O(n^2) time, O(n^2) space
    
    void bfs(vector<vector<char>> &board, const int x, const int y) {
        int N = board.size();
        int M = board.front().size();
        
        queue<pair<int, int>> qq;   //  queue for BFS
        
        pair<int, int> pos;     //  temp, position (x, y)

        qq.push(make_pair(x, y));   //  start BFS
        board[x][y] = 'V';
        
        while (qq.empty() == false) {
            pos = qq.front();
            qq.pop();
            
            if (pos.first > 0 && board[pos.first - 1][pos.second] == 'O') {
                qq.push(make_pair(pos.first - 1, pos.second));
                board[pos.first - 1][pos.second] = 'V';
            }  //  up
            
            if (pos.first < N - 1 && board[pos.first + 1][pos.second] == 'O') {
                qq.push(make_pair(pos.first + 1, pos.second));
                board[pos.first + 1][pos.second] = 'V';
            }  //  down
                
            if (pos.second > 0 && board[pos.first][pos.second - 1] == 'O') {
                qq.push(make_pair(pos.first, pos.second - 1));
                board[pos.first][pos.second - 1] = 'V';
            }  //  left
            
            if (pos.second < M - 1 && board[pos.first][pos.second + 1] == 'O') {
                qq.push(make_pair(pos.first, pos.second + 1));
                board[pos.first][pos.second + 1] = 'V';
            }  //  right
        }
    }   //  O(n^2) time, O(n^2) space
};