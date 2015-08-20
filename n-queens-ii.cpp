/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/

class Solution {
public:
    int totalNQueens(int n) {
        if (n == 0) return 0;
        
        int pos[n];
        return totalNQueens(pos, n, 0);
    }	//	O(n^3) time, O(n) space
    
    int totalNQueens(int pos[], int n, int depth) {
        if (n == depth) return 1;	//	found one solution !!
        
        int ans = 0;

        for (int i = 0; i < n; i++) {
            pos[depth] = i;
            if (check(pos, depth))  ans += totalNQueens(pos, n, depth+1);
        }

        return ans;
    }
    
    bool check(int pos[], int depth) {
        if (depth == 0) return true;
        
        for (int i = 0; i < depth; i++) {
            if (pos[i] == pos[depth])   return false;	//  same col            
            if (abs(pos[i] - pos[depth]) == (depth - i))  return false;	//  diagonal line
            //	no need to check if same row, since we append row by row
        }
        
        return true;
    }	//	O(n) time, O(1) space
};