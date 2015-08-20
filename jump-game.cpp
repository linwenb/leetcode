/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

class Solution {
public:
    bool canJump(int A[], int n) {
        if (n <= 1) return true;
        
        int reach = 0;	//	how far it can reach so far

        for (int i = 0; i < n; i++) {
            if (reach < i)  return false;   //  cannot reach i
            
            if (reach < i + A[i])   reach = i + A[i];	//	if jump further from i
            
            if (reach >= n - 1) return true;    //  reach end
        }
    }	//	O(n) time, O(1) space
};