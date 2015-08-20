/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int row = matrix.size();
        if (row == 0)   return 0;
        
        int col = matrix.front().size();
        if (col == 0)   return 0;
        
        int ans = 0;
        int area;
        
        vector<int> bars(col, 0);
        
        for (int i = 0; i < row; i++) {            
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') {
                    bars[j]++;
                }
                else {
                    bars[j] = 0;
                }
            }	//  calculate height on each row
                        
            area = maximalRectangle(bars, col);	//  use algorithm for largest-rectangle-in-histogram
            
            if (area > ans) ans = area;
        }	//  process row by row
        
        return ans;
    }	//	O(n^2) time, O(n) space
    
    int maximalRectangle(vector<int> &bars, n) {
        int i = 0;
        int tp;         //  index storing top bar
        int ans = 0;    //  max area
        int area;
        stack<int> stk;
        
        //  6,2,5,4,5
        //  6
        //  2
        //  2,5
        //  2,4
        //  2,4,5
        while (i < n) {
            if (stk.empty() == true || bars[stk.top()] <= bars[i]) {
                stk.push(i);	//	insert once
                i++;
            }
            else {	//	compute area, since bars[stk.top()] contribute nothing starting from i
                tp = stk.top();
                stk.pop();		//	and pop once
                
                // Calculate the area with hist[tp] stack as smallest bar starting from i
                //  1,3,4,5,2 will calculate 5; 4,5; 3,4,5
                area = bars[tp] * (stk.empty() ? i : i - stk.top() - 1);
                
                if (area > ans) ans = area;
            }   //  bars[stk.top()] > bars[i]
        }
        
        //  remaining increasing bars in stack
        while (stk.empty() == false) {
            tp = stk.top();
            stk.pop();
            
            area = bars[tp] * (stk.empty() ? i : i - stk.top() - 1);
            
            if (area > ans) ans = area;
        }
        
        return ans;
    }	//	O(n) time, O(n) space
};