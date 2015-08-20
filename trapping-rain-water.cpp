/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
*/

class Solution {
public:
    int trap(int A[], int n) {
        if (n < 3)  return 0;
        
        int all = 0;    //  area of water and bars
        int block = 0;  //  area of bars
        int maxHt = 0;  //  current max height
        int minHt;
        
        int s = 0;      //  left index
        int e = n - 1;  //  right index
        
        while (s <= e) {
            minHt = min(A[s], A[e]);
            
            if (maxHt < minHt)  maxHt = minHt;	//	update max height comparing with the shorter one
            
            //	move the shorter bar
            if (A[s] < A[e]) {
                block += A[s];
                s++;
            }
            else {
                block += A[e];
                e--;
            }
            
            all += maxHt;	//	keep adding the max height
        }
        
        return all - block;	//	area of water
    }	//	O(n) time, O(1) space
};