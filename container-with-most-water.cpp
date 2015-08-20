/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

class Solution {
public:
    int ans(vector<int> &height) {
        int n = height.size();
        if (n < 2)  return 0;   //  connot form a container
        
        int start = 0;
        int end = height.size() - 1;

        int ans = 0;
        int tempArea;
        //  start from the two ends
        //  larger area must be narrower and higher
        while (start < end) {
            tempArea = min(height[start], height[end]) * (end - start);
            
            if (tempArea > ans) ans = tempArea;
            
            //  move the shorter one, which limits the height
            if (height[start] < height[end])    start++;
            else    end--;
        }
        
        return ans;
    }   //  O(n) time, O(1) space
};