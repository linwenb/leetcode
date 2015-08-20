/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int n = height.size();
        if (n == 0) return 0;
        
        int i = 0;
        int tp;         //  index storing top bar
        int ans = 0;    //  max area
        int area;
        stack<int> stk;

        while (i < n) {
            if (stk.empty() == true || height[stk.top()] <= height[i]) {
                stk.push(i);	//	insert once
                i++;
            }
            else {	//	compute area, since bars[stk.top()] contribute nothing starting from i
                tp = stk.top();
                stk.pop();		//	and pop once
                
                // Calculate the area with hist[tp] stack as smallest bar starting from i
                //  1,5,6,2 will calculate 6; 5,6
                area = height[tp] * (stk.empty() ? i : i - stk.top() - 1);
                
                if (area > ans) ans = area;
            }   //  height[stk.top()] > height[i]
        }
        
        //  remaining increasing bars in stack
        while (stk.empty() == false) {
            tp = stk.top();
            stk.pop();
            
            area = height[tp] * (stk.empty() ? i : i - stk.top() - 1);
            
            if (area > ans) ans = area;
        }
        
        return ans;
    }	//	O(n) time, O(n) space
};